# **Prosjektoppgave i C++ Vår 2013**

# **BeepTracker**

### *av: Ole Aarnseth (s180482), Vegard Krusedokken (s164830) og Aril Schultzen (s180470)*


## **Innledning**
BeepTracker er et program som benytter seg av den interne PC speakeren som finnes på hovedkortet i de fleste PCer, til å lage lyd. Programmet har to modus, et for piano og et for komponering av sanger («Piano» og «Composer»). «Composer» er et begrenset verktøy for komponering da metoden for å fremstille lyd bare tillater oss å lage en tone om gangen. Det var et mål for programmet at det skulle være mulig å plotte inn noter fra et noteark og at programmet skulle kunne spille av dette på en korrekt måte i forhold til tempo og taktart. Dette har til en viss grad blitt implementert. 

##**Merknader**
Programmet er skrevet for Linux, og er testet i nyere versjoner av Debian (6 og 7) og Ubuntu (10.10 og 12.10). Det er avhengig av Ncurses (libncurses5-dev). Programmet må kjøres som root for å lage lyd.  

På mange nye distroer er pcspkr enheten svartelistet under. Den aktuelle listen er: */etc/modprobe.d/blacklist.conf*

 I noen distroer er den også muted, her kan det være greit å sjekke Alsamixer.

## **Lyd**

Siden PC speaker er en del av Linux Console, og er derfor et «character device», kan en manipulere den ved hjelp av ioctl(). Den tar imot en frekvens og en tid i ms, og spiller av en sinuskurve ved en spesifisert frekvens over en bestemt tid. Det er ikke mulighet for å spille av noen annen form for kurve, slik som sagtann eller firkant. Dette begrenser igjen hva en kan gjøre med tanke på perkusjon samt andre effekter.

## **Oppbygning**

Programmet er bygget opp slik at det skal ligne et noteark. En låt består av takter som igjen består av noter. Under er noen sentrale klasser beskrevet:

#### **class_note.cpp/h**
Ei note består hovedsakelig av en streng som beskriver tonen den gir, f.eks. A#3 (En A med et kryss (en halvtone ned), 3 oktav.) samt et tall for lengde. En notelengde er egentlig en brøk f.eks. 1/4, 1/8, 1/16 osv. Når en spesifiserer notelengden, bestemmer en nevnerdelen av brøken, da tellerdelen er av praktiske årsaker gjort implisitt. Hvis en note lages av lengde 8, betyr dette i praksis 1/8.    

#### **class_bar.cpp/h**
En bar (eller takt på norsk) består av noter. For enkelthetens skyld har vi avgrenset slik at det kun finnes en taktart, 4/4. Dette er selvsagt ufint med hensyn til de som prefererer en god vals (1/3 taktart). En bar holder også rede på hvor mye tid (eller plass avhengig av syn) som er igjen i seg selv, noe som er viktig om en skal opprettholde en taktart.

#### **class_song.cpp/h**
En låt består av bars, et navn og en hastighet (oppgitt i BPM). 


#### **class_sound.cpp/h**
I denne klassen finnes flere viktige funksjoner:

	void playSequence(std::vector<note_t> param)
	
Funksjonen tar imot en vector av tone_t (struct) som igjen består av en frekvens og en lengde, og spiller av disse. 

	std::vector<note_t> parse(std::vector<bar> bars, int bpm)

Siden funksjonen som lager lyden kun tar imot en frekvens og en lengde i ms, brukes denne funksjonen til å oversette fra strings til frekvens (ved hjelp av class_freqnote.cpp/h) samt fra et enkelt tall til ms (se calculateLength(double length, int bpm)). Funksjonen fyller også en takt med pausenoter, hvis takten ikke er fullstendig fylt opp av noter. Til slutt returnerer den det oversatte innholdet i  form av en vector.  

	int calculateLength(double length, int bpm)

Funksjonen tar imot en tonelengde (2,4,8,16 osv) og BPM og konverterer til ms. 

## **Bruk av Ncurses**
Ncurses er brukt for å få mer kontroll over terminalen og for enklere å skrive «GUI». 

#### **class_tools.cpp/h**
Da Ncurses bruker c-style strings, fant vi fort behovet for en klasse hvor vi kunne ha alle konverteringsfunksjoner. Disse ble lagt i class_tools.

## **Til senere utgivelser**
Da vi ikke rakk å gjøre alt vi ønsket, ble noen ting nedprioritert. Blant disse er:

- Støtte for flere taktarter.
- Mulighet til å lage «elements», små blokker bestående av korte noter satt sammen slik at de etterliknet diverse effekter som arpeggioer, perkusjon osv.
- Lagring til fil.
- Simulering av polyfoni for mer komplisert musikk.
- Ikke mulig å sette inn en tone mellom to toner.
- Bedre feilmeldinger, med bedre tid kunne vi implmenetert mer beskrivende og spesifikke feilmeldinger.
- Gruppemedlem Ole Aarnseth (s180482) jobbet med en bedre GUI for tracker mode, men vi fikk desverre aldri tid til å implementere den skikkelig og måtte droppe all koden vi hadde for den (koden kan ses under klassene formField og trackerGUI i tidligere commits.) Det var egentlig aldri meningen at class tracker skulle være den endelige GUIen til tracker mode.

## **Feil ved commit-oversikten på github**
Det oppstod noe feil ved bruk av commit for Vegard Krusedokken (s164830), slik at commit-oversikten på github ikke viser riktig antall commits og linjer/endringer.  Github viser commits for to emails: vegard@D531 og ﻿s164830@stud.hioa.no, men bare en av emailenes commits er blitt registrert på grafen.
