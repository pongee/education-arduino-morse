// Morze pin-je.
const int morzePin = 8;

// Beallitjuk a morze sipolas milyen hangfrekvencian szolaljon meg. 
const int morzeHangfrekvencia = 100;

// Beallitjuk hogy a morze jelek mennyi ideig tartsanak.
const int rovidMorzeIdeje  = 1000; // 1 masodperc
const int hosszuMorzeIdeje = 3000; // 3 masodperc

// Beallitjuk hogy ketto morze jel kozotti mennyi ideig varjunk.
const int morzekKozottiVarakozasiIdo = 3000; // 3 masodperc

// Beallitjuk hogy ketto betu kozott mennyi ideig varjunk
const int betukKozottiVarakozasiIdo = 5000; // 5 masodperc

// Angol abc morze-val lekodolva.
const char a[] = ".-";
const char b[] = "-...";
const char c[] = "-.-.";
const char d[] = "-..";

const char e[] = ".";
const char f[] = "..-.";
const char g[] = "--.";
const char h[] = "....";
const char i[] = "..";

const char j[] = ".---";
const char k[] = "-.-";
const char l[] = ".-..";
const char m[] = "--";
const char n[] = "-.";

const char o[] = "---";
const char p[] = ".--.";
const char q[] = "--.-";
const char r[] = ".-.";
const char s[] = "...";

const char t[] = "-";
const char u[] = "..-";
const char v[] = "...-";
const char w[] = ".--";
const char x[] = "-..-";

const char y[] = "-.--";
const char z[] = "--..";

// A szoveg amit szeretnenk morzeval kodolni. 
const char * const szoveg[] = {h,e,l,l,o};

void setup() {
  pinMode(morzePin, OUTPUT); // Beallitjuk hogy a "morzePin" az egy "OUTPUT" vagyis kimenet.
    
  Serial.begin(9600);
  Serial.println("\n Morze kod");
}

void loop() {
  // Kiszamoljuk a szovegunk hosszat. 
  int szovegHossza = (byte)(sizeof(szoveg) / sizeof(szoveg)[0]);
  
  // Vegigmegyunk a szovegunkon beturol beture.
  for (int betuSorszama = 0; betuSorszama < szovegHossza; betuSorszama = betuSorszama + 1) {
    int morzeSorszama = 0;
    
    do {
      if (szovegValahanyadikKaraktere(betuSorszama, morzeSorszama) == '.') {
        // Bekapcsoljuk a hangszorot a megfelelo hangfrekvencian,
        // majd rovid ideig varunk, es utana kikapcsoljuk
        tone(morzePin, morzeHangfrekvencia);
        
        delay(rovidMorzeIdeje); 

        noTone(morzePin);
        
        Serial.print(".");
      } else if (szovegValahanyadikKaraktere(betuSorszama, morzeSorszama)  == '-') {
        // Bekapcsoljuk a hangszorot a megfelelo hangfrekvencian,
        // majd hosszu ideig varunk, es utana kikapcsoljuk
        tone(morzePin, morzeHangfrekvencia);
        
        delay(hosszuMorzeIdeje);
        
        noTone(morzePin);
        
        Serial.print("-");
      }
      
      delay(morzekKozottiVarakozasiIdo);

      morzeSorszama++;
    } while (szovegValahanyadikKaraktere(betuSorszama, morzeSorszama) == '.' || szovegValahanyadikKaraktere(betuSorszama, morzeSorszama) == '-');
    
    delay(betukKozottiVarakozasiIdo);
    Serial.println("");
  }
}

// Elkerhetjuk a szovegunk valahanyadik betujenek valahanyadik morze jelet.
char szovegValahanyadikKaraktere(int betuSorszama, int morzeSorszama) {
  return szoveg[betuSorszama][morzeSorszama];
}
