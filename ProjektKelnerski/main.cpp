#include <iostream>
#include "naglowek.h"
#include <thread>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
	SetConsoleCP(852);
	setlocale(LC_ALL, "");

	while (true)
	{
		int kod{};
		cout << "Jeśli chcesz wyjść z programu, wpisz 0\n \nPodaj swój kod\n";
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
				cout << "Jeśli chcesz opuścić program, wpisz 0 \nCo chcesz zrobić? \n1 - zmienić swój kod\n2 - zobaczyć zawartość stolika\n3 - dodać pozycję do stolika\n4 - sfinalizować rachunek";
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
						cout << "Nie masz wystarczających uprawnień! Podaj kod administratora lub wpisz 0 by wrócić:"; //zmiana kodu za zgoda admina
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
								cout << "Wprowadź nowy kod";
								int nowykod{}, tymnowy{};
								cin >> nowykod;
								if (CzyKodPoprawny(nowykod) != 1)//czy kod do kogoť nie nale┐y
								{
									cout << "Przykro mi, ale musisz wybrać inny kod.";
									this_thread::sleep_for(3s);
									continue;
								}
								cout << "Potwierdź nowy kod";//czy kody s╣ identyczne
								cin >> tymnowy;
								if (nowykod == tymnowy)
								{
									ZmianaKodu(kod, nowykod);
									kod = nowykod;
									break;
								}
								else
								{
									cout << "Kody się różnią!  Czy chcesz spróbować ponownie? (t/n)\n";//mo┐liwoťŠ powtˇrzenia
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
							cout << "Kod niepoprawny. Mam nadzieję, że nie próbujesz się włamać :)";//jeťli nie podamy kody admina
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
						cout << "Który stolik chcesz otworzyć?";
						int wyborstolika{};
						cin >> wyborstolika;

						if (wyborstolika > 0 && wyborstolika < 5)//tylko 4 stoliki wiec sprawdzam czy istnieje
						{
							wyswietlstolik(wyborstolika);
							cout << "Wciśnij dowolny znak, aby przejść dalej";
							char cokolwiek{};
							cokolwiek = _getch();
							break;

						}
						else
						{
							cout << "Nie ma takiego stolika. Czy chcesz spróbować jeszcze raz? (t/n)";
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
						cout << "Do którego stolika chcesz coś dodać?";
						int numerstolika{};
						cin >> numerstolika;
						if (numerstolika > 0 && numerstolika < 5)//spr nr stolika
						{
							while (true)
							{


								system("cls");
								cout << "Co chcesz dodać do stolika?\n1 - potrawę \n2 - wino";
								int wybdodania{};
								cin >> wybdodania;
								switch (wybdodania)
								{
								case 1:
								{
									system("cls");
									wyswietlpotrawy();
									cout << endl << "Podaj numer dania, które chcesz dodać.";
									int danie{};
									cin >> danie;
									if (danie > 0 && danie < 20)// spr nr dania (dlatego te┐ ostatecznie zrezygnowa│am z funkcji dodawania da˝, gdy┐ zawsze mamy 19 da˝ inaczej musialabym to sprawdzaŠ z plikiem za ka┐dym razem przy u┐ywaniu teog 
									{
										potrawacenawino(numerstolika, danie);
										cout << "Danie zostało pomyślnie dodane.";
										this_thread::sleep_for(5s);
										break;
									}
									else
									{
										cout << "Podane danie nie istnieje. Czy chcesz spróbować ponownie?";
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
									cout << endl << "Podaj numer wina, które chcesz dodać.";
									int wino{}, glassbottle;
									cin >> wino;
									cout << endl << "Kieliszek(1) czy butelka(2)?";
									cin >> glassbottle;
									if (wino > 0 && wino < 20 && (glassbottle == 1 || glassbottle == 2))
									{
										winodokoszyka(numerstolika, wino, glassbottle);
										cout << "Wino zostało pomyślnie dodane.";
										this_thread::sleep_for(3s);
										break;
									}
									else
									{
										cout << "Podane wino bądź wybrana wartość przy wybieraniu pojemności nie istnieje. Czy chcesz spróbować ponownie?(t/n)";
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
							cout << "Niestety taki stolik nie istnieje. Czy chcesz spróbować ponownie? (t/n)\n"; // a tu co jakby stolik nie istnia│
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
						cout << "Który stolik pragniesz zamknąć?";
						int nrstolika;
						cin >> nrstolika;
						if (nrstolika > 0 && nrstolika < 5)
						{
							while (true)
							{
								cout << "Jaki będzie sposób płatności ? Gotówką(1) czy kartą(2) ? ";
								int platnosc{};
								cin >> platnosc;
								if (platnosc == 1 || platnosc == 2)
								{
									system("cls");
									drukowanie(nrstolika, platnosc);
									cout << "\n\nAby zamknąć wciśnij dowolny przycisk.";
									char cokolwiek;
									cokolwiek = _getch();
									exit(0);
									break;
								}
								else
								{
									cout << "Nie ma takiej metody płatności, spróbuj ponownie.";
									this_thread::sleep_for(3s);
									continue;
								}
							}
							break;
						}
						else
						{
							cout << "Podany stolik nie istnieje! Czy chcesz spróbować ponownie? (t/n)";
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
					cout << "Zła liczba, proszę spróbować ponownie";
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
				cout << "Jeśli chcesz wyjść z programu, wpisz 0\n \nCo chcesz zrobić?\n1 - dodanie pracownika\n2 - usunięcie pracownika\n3 - zmiana własnego kodu";
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
						cout << "Podaj kod nowego pracownika.";
						int nowykod{}, tymnowy;
						cin >> nowykod;
						if (CzyKodPoprawny(nowykod) != 1)
						{
							cout << "Przykro mi, ale musisz wybrać inny kod.";
							this_thread::sleep_for(3s);
							continue;
						}
						cout << "Potwierdź kod nowego pracownika";
						cin >> tymnowy;
						if (nowykod != tymnowy)
						{
							cout << "Podane kody nie są identyczne! Czy chcesz spróbować ponownie? (t/n)";
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
						cout << "Podaj kod pracownika, którego chcesz usunąć.";
						int starykod{};
						cin >> starykod;
						if (CzyKodPoprawny(starykod) == 1)
						{
							cout << "Podany kod nie istnieje, czy chcesz spróbować ponownie (t/n)? ";
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
							cout << "Nie możesz usunąć siebie głuptasie.";
							this_thread::sleep_for(3s);
							continue;
						}
						else
						{
							cout << "Potwierdź wprowadzony kod:";
							int tymstary{};
							cin >> tymstary;
							if (starykod == tymstary)
							{
								UsunieciePracownika(starykod);
							}
							else
							{
								cout << "Podane kody nie pasują, czy chcesz spróbować ponownie (t/n)? ";
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
						cout << "Potwierdź swój kod";
						int nowykod{};
						cin >> nowykod;
						if (nowykod == kod)
						{
							while (true)
							{
								system("cls");
								cout << "Wprowadź nowy kod";
								int tymnowy{};
								cin >> nowykod;
								if (CzyKodPoprawny(nowykod) != 1)
								{
									cout << "Przykro mi, ale musisz wybrać inny kod.";
									this_thread::sleep_for(3s);
									continue;
								}
								cout << "Potwierdź nowy kod";
								cin >> tymnowy;
								if (nowykod == tymnowy)
								{
									ZmianaKodu(kod, nowykod);
									kod = nowykod;
									break;
								}
								else
								{
									cout << "Podane kody nie pasują, czy chcesz spróbować ponownie (t/n)? ";
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
							cout << "Nieprawidłowy kod!\nCzy chcesz ponowić próbę? (t/n)";
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
					cout << "nieprawidłowa wartość";
					this_thread::sleep_for(2s);
					break;
				}
			}
		}
		else if (CzyKodPoprawny(kod) == 1)
		{
			cout << "KOD NIEPOPRAWNY, SPRÓBUJ PONOWNIE ZA 5 SEKUND";
			this_thread::sleep_for(5s);
		}



		system("cls"); //u u czyscimy u u 
	}
}
