#include <iostream>
#include "naglowek.h"
#include <thread>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {

	while (true)
	{
		int kod{};
		cout << "Jeli chcesz wyj† z programu, wpisz 0\n \nPodaj sw˘j kod\n";
		cout << "\n     /$$    /$$$$$$   /$$$$$$   \n   /$$$$   /$$__  $$ /$$__  $$  \n  |_  $$  |__/  \\ $$|__/  \\ $$  \n    | $$    /$$$$$$/   /$$$$$/  \n    | $$   /$$____/   |___  $$  \n    | $$  | $$       /$$  \\ $$  \n   /$$$$$$| $$$$$$$$|  $$$$$$/  \n  |______/|________/ \\______/   \n                                \n   /$$   /$$ /$$$$$$$   /$$$$$$ \n  | $$  | $$| $$____/  /$$__  $$\n  | $$  | $$| $$      | $$  \\__/\n  | $$$$$$$$| $$$$$$$ | $$$$$$$ \n  |_____  $$|_____  $$| $$__  $$\n        | $$ /$$  \\ $$| $$  \\ $$\n        | $$|  $$$$$$/|  $$$$$$/\n        |__/ \\______/  \\______/ \n                                \n   /$$$$$$$$ /$$$$$$   /$$$$$$  \n  |_____ $$//$$__  $$ /$$__  $$ \n       /$$/| $$  \\ $$| $$  \\ $$ \n      /$$/ |  $$$$$$/|  $$$$$$$ \n     /$$/   >$$__  $$ \\____  $$ \n    /$$/   | $$  \\ $$ /$$  \\ $$ \n   /$$/    |  $$$$$$/|  $$$$$$/ \n  |__/      \\______/  \\______/  ";
		cout << endl;
		cin >> kod;

		if (kod == 0)
			exit(0);
		else if (CzyKodPoprawny(kod) == 5)
		{
			while (true)//UZYTKOWNIK
			{
				system("cls");
				cout << "Jeli chcesz opuci† program, wpisz 0 \nCo chcesz zrobi†? \n1 - zmieni† sw˘j kod\n2 - zobaczy† zawarto† stolika\n3 - doda† pozycj© do stolika\n4 - sfinalizowa† rachunek" << endl;
				int wybor{};
				cin >> wybor;
				switch (wybor)
				{
				case 0: {
					exit(0);
				}
				case 1:
				{
					while (true)
					{
						system("cls");
						cout << "Nie masz wystarczajĄcych uprawnieä! Podaj kod administratora lub wpisz 0 by wr˘ci†:" << endl; //zmiana kodu za zgoda admina
						int corobisz{};
						cin >> corobisz;
						if (corobisz == 0)
						{
							break;
						}
						else if (CzyKodPoprawny(corobisz) == 7)//czy kod jest kodem admina
						{
							while (true)
							{
								system("cls");
								cout << "Wprowad« nowy kod" << endl;
								int nowykod{}, tymnowy{};
								cin >> nowykod;
								if (CzyKodPoprawny(nowykod) != 1)//czy kod do kogoś nie należy
								{
									cout << "Przykro mi, ale musisz wybra† inny kod.";
									this_thread::sleep_for(3s);
									continue;
								}
								cout << "Potwierd« nowy kod" << endl;//czy kody są identyczne
								cin >> tymnowy;
								if (nowykod == tymnowy)
								{
									ZmianaKodu(kod, nowykod);
									kod = nowykod;
									break;
								}
								else
								{
									cout << "Kody si© r˘ľniĄ!  Czy chcesz spr˘bowa† ponownie? (t/n)\n";//możliwość powtórzenia
									char cokol{};
									cin >> cokol;
									if (CzyChceszKontynuowac(cokol))
										continue;
									else
										break;
								}
								break;
							}
							break;
						}
						else
						{
							cout << "Kod niepoprawny. Mam nadziej©, ľe nie pr˘bujesz si© wama† :)";//jeśli nie podamy kody admina
							this_thread::sleep_for(3s);
							continue;
						}
					}
					break;
				}
				case 2:
				{
					while (true)
					{
						system("cls");
						stoliczkiwrestauracji();//wyswietlonko stolikow
						cout << "Kt˘ry stolik chcesz otworzy†?" << endl;
						int wyborstolika{};
						cin >> wyborstolika;

						if (wyborstolika > 0 && wyborstolika < 5)//tylko 4 stoliki wiec sprawdzam czy istnieje
						{
							wyswietlstolik(wyborstolika);
							cout << "Wcinij dowolny znak, aby przej† dalej";
							char cokolwiek{};
							cokolwiek = _getch();
							break;

						}
						else
						{
							cout << "Nie ma takiego stolika. Czy chcesz spr˘bowa† jeszcze raz? (t/n)" << endl;
							char kontynuacja{};
							cin >> kontynuacja;
							if (CzyChceszKontynuowac(kontynuacja))
								continue;
							else
								break;

						}

					}
					break;
				}
				case 3:
				{
					while (true)
					{
						system("cls");
						stoliczkiwrestauracji();
						cout << "Do kt˘rego stolika chcesz co doda†?" << endl;
						int numerstolika{};
						cin >> numerstolika;
						if (numerstolika > 0 && numerstolika < 5)//spr nr stolika
						{
							while (true)
							{


								system("cls");
								cout << "Co chcesz doda† do stolika?\n1 - potraw© \n2 - wino" << endl;
								int wybdodania{};
								cin >> wybdodania;
								switch (wybdodania)
								{
								case 1:
								{
									system("cls");
									wyswietlpotrawy();
									cout << endl << "Podaj numer dania, kt˘re chcesz doda†." << endl;
									int danie{};
									cin >> danie;
									if (danie > 0 && danie < 20)// spr nr dania (dlatego też ostatecznie zrezygnowałam z funkcji dodawania dań, gdyż zawsze mamy 19 dań inaczej musialabym to sprawdzać z plikiem za każdym razem przy używaniu teog 
									{
										potrawacenawino(numerstolika, danie);
										cout << "Danie zostao pomylnie dodane.";
										this_thread::sleep_for(5s);
										break;
									}
									else
									{
										cout << "Podane danie nie istnieje. Czy chcesz spr˘bowa† ponownie?" << endl;
										char danko{};
										cin >> danko;
										if (CzyChceszKontynuowac(danko))
											continue;
										else
											break;
									}
								}
								case 2:
								{
									system("cls");
									wyswietlwina();
									cout << endl << "Podaj numer wina, kt˘re chcesz doda†." << endl;
									int wino{}, glassbottle;
									cin >> wino;
									cout << endl << "Kieliszek(1) czy butelka(2)?" << endl;
									cin >> glassbottle;
									if (wino > 0 && wino < 20 && (glassbottle == 1 || glassbottle == 2))
									{
										winodokoszyka(numerstolika, wino, glassbottle);
										cout << "Wino zostao pomylnie dodane.";
										this_thread::sleep_for(3s);
										break;
									}
									else
									{
										cout << "Podane wino bĄd« wybrana warto† przy wybieraniu pojemnoci nie istnieje. Czy chcesz spr˘bowa† ponownie?(t/n)" << endl;
										char danko{};
										cin >> danko;
										if (CzyChceszKontynuowac(danko))
											continue;
										else
											break;
									}
								}
								default:
								{
									cout << "Przykro mi, ale wybrana przez ciebie opcja nie istnieje.";//troche sadge ;c
									this_thread::sleep_for(3s);
									break;
								}
								}
								break;
							}
						}
						else
						{
							cout << "Niestety taki stolik nie istnieje. Czy chcesz spr˘bowa† ponownie? (t/n)\n"; // a tu co jakby stolik nie istniał
							char stolczor{};
							cin >> stolczor;
							if (CzyChceszKontynuowac(stolczor))
								continue;
							else
								break;
						}
						break;
					}
					break;
				}
				case 4:
				{
					while (true)
					{
						system("cls");
						stoliczkiwrestauracji();
						cout << "Kt˘ry stolik pragniesz zamknĄ†?" << endl;
						int nrstolika;
						cin >> nrstolika;
						if (nrstolika > 0 && nrstolika < 5)
						{
							while (true)
							{
								cout << "Jaki b©dzie spos˘b patnoci ? Got˘wkĄ(1) czy kartĄ(2) ? " << endl;
								int platnosc{};
								cin >> platnosc;
								if (platnosc == 1 || platnosc == 2)
								{
									system("cls");
									drukowanie(nrstolika, platnosc);
									cout << "\n\nAby zamknĄ† wcinij dowolny przycisk.";
									char cokolwiek;
									cokolwiek = _getch();
									exit(0);
									break;
								}
								else
								{
									cout << "Nie ma takiej metody patnoci, spr˘buj ponownie.";
									this_thread::sleep_for(3s);
									continue;
								}
							}
							break;
						}
						else
						{
							cout << "Podany stolik nie istnieje! Czy chcesz spr˘bowa† ponownie? (t/n)" << endl;
							char zamk{};
							cin >> zamk;
							if (CzyChceszKontynuowac(zamk))
								continue;
							else
								break;
						}
					}
					break;
				}
				default:
				{
					system("cls");
					cout << "Za liczba, prosz© spr˘bowa† ponownie";
					this_thread::sleep_for(2s);
					break;
				}
				}

				system("cls");
			}

		}
		else if (CzyKodPoprawny(kod) == 7)
		{
			while (true)//ADMIN
			{
				system("cls");
				cout << "Jeli chcesz wyj† z programu, wpisz 0\n \nCo chcesz zrobi†?\n1 - dodanie pracownika\n2 - usuni©cie pracownika\n3 - zmiana wasnego kodu" << endl;
				int decyzja{};
				cin >> decyzja;

				switch (decyzja)
				{
				case 0: {
					exit(0);
				}
				case 1: {
					while (true)
					{
						system("cls");
						cout << "Podaj kod nowego pracownika." << endl;
						int nowykod{}, tymnowy;
						cin >> nowykod;
						if (CzyKodPoprawny(nowykod) != 1)
						{
							cout << "Przykro mi, ale musisz wybra† inny kod.";
							this_thread::sleep_for(3s);
							continue;
						}
						cout << "Potwierd« kod nowego pracownika" << endl;
						cin >> tymnowy;
						if (nowykod != tymnowy)
						{
							cout << "Podane kody nie sĄ identyczne! Czy chcesz spr˘bowa† ponownie? (t/n)" << endl;
							char proba{};
							cin >> proba;
							if (CzyChceszKontynuowac(proba))
								continue;
							else
								break;
						}
						else
						{
							DodaniePracownika(nowykod);
							break;
						}
					}
					break; }
				case 2: {
					while (true)
					{
						system("cls");
						cout << "Podaj kod pracownika, kt˘rego chcesz usunĄ†." << endl;
						int starykod{};
						cin >> starykod;
						if (CzyKodPoprawny(starykod) == 1)
						{
							cout << "Podany kod nie istnieje, czy chcesz spr˘bowa† ponownie (t/n)? " << endl;
							char kontynuacja{};
							cin >> kontynuacja;
							if (CzyChceszKontynuowac(kontynuacja))
								continue;
							else
								break;
						}
						else if (CzyKodPoprawny(starykod) == 7)
						{
							PlaySound(TEXT("rickroll.wav"), NULL, SND_ASYNC);//never gonna let u down, never gonna say goodbyeeeee
							rickroll();
							cout << "Nie moľesz usunĄ† siebie guptasie.";
							this_thread::sleep_for(3s);
							continue;
						}
						else
						{
							cout << "Potwierd« wprowadzony kod:" << endl;
							int tymstary{};
							cin >> tymstary;
							if (starykod == tymstary)
							{
								UsunieciePracownika(starykod);
							}
							else
							{
								cout << "Podane kody nie pasujĄ, czy chcesz spr˘bowa† ponownie (t/n)? " << endl;
								char proba{};
								cin >> proba;
								if (CzyChceszKontynuowac(proba))
									continue;
								else
									break;
							}
							break;
						}

					}
					break; }
				case 3: {
					while (true)
					{
						system("cls");
						cout << "Potwierd« sw˘j kod" << endl;
						int nowykod{};
						cin >> nowykod;
						if (nowykod == kod)
						{
							while (true)
							{
								system("cls");
								cout << "Wprowad« nowy kod" << endl;
								int tymnowy{};
								cin >> nowykod;
								if (CzyKodPoprawny(nowykod) != 1)
								{
									cout << "Przykro mi, ale musisz wybra† inny kod.";
									this_thread::sleep_for(3s);
									continue;
								}
								cout << "Potwierd« nowy kod" << endl;
								cin >> tymnowy;
								if (nowykod == tymnowy)
								{
									ZmianaKodu(kod, nowykod);
									kod = nowykod;
									break;
								}
								else
								{
									cout << "Podane kody nie pasujĄ, czy chcesz spr˘bowa† ponownie (t/n)? " << endl;
									char sproba{};
									cin >> sproba;
									if (CzyChceszKontynuowac(sproba))
										continue;
									else
										break;
								}
							}
						}
						else
						{
							cout << "Nieprawidowy kod!\nCzy chcesz ponowi† pr˘b©? (t/n)" << endl;
							char kontynuacja{};
							cin >> kontynuacja;
							if (CzyChceszKontynuowac(kontynuacja))
								continue;
							else
								break;
						}
						break;
					}
					break; }
				default:
					cout << "nieprawidowa warto†";
					this_thread::sleep_for(2s);
					break;
				}
			}
		}
		else if (CzyKodPoprawny(kod) == 1)
		{
			cout << "KOD NIEPOPRAWNY, SPRŕBUJ PONOWNIE ZA 5 SEKUND";
			this_thread::sleep_for(5s);
		}



		system("cls"); //u u czyscimy u u 
	}
}
