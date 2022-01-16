#include <iostream>
#include "naglowek.h"
#include <string>
#include <fstream>
#include <thread>
#include <conio.h>

using namespace std;


bool CzyChceszKontynuowac(char kontynuacja)
{
	if (kontynuacja == 'n' || kontynuacja == 'N')
	{
		return 0;
	}
	else
	{
		if (kontynuacja != 't' && kontynuacja != 'T')
		{
			cout << "Niestety nie rozumiem znaku, który został wprowadzony. Domyślam się jednak, że chodziło o kontynuację.";
			this_thread::sleep_for(3s);
			return 1;
		}
		return 1;
	}

}

int CzyKodPoprawny(int kod)
{
	fstream kodzik;
	kodzik.open("kody.txt", ios::in);
	if (kodzik.good() == false)
	{
		cout << "Niestety ktoś usunął niezbędny do działania systemu plik! Proszę skontaktować się z pomocą.";
		this_thread::sleep_for(10s);
		exit(0);
	}
	string linia{};
	int numerlinii = 1;
	while (getline(kodzik, linia))
	{
		if (numerlinii == 1)
		{
			if (atoi(linia.c_str()) == kod)
			{
				kodzik.close();
				return 7;
			}
		}
		else
		{
			if (atoi(linia.c_str()) == kod)
			{
				kodzik.close();
				return 5;
			}
		}
		numerlinii++;
	}

	kodzik.close();
	return 1;
}

void DodaniePracownika(int nowykod)
{
	fstream kodzik;
	kodzik.open("kody.txt", ios::out | ios::app);
	kodzik << endl << to_string(nowykod);
	kodzik.close();
}

void UsunieciePracownika(int starykod)
{
	fstream kodzik;
	kodzik.open("kody.txt", ios::in);
	int n{};
	string linia1{};
	while (!kodzik.eof())
	{
		getline(kodzik, linia1);
		n++;
	}
	string* tablica = new string[n];

	int numerlinii = 1;
	string linia{};
	kodzik.close();
	kodzik.open("kody.txt", ios::in);

	while (getline(kodzik, linia))
	{
		if (atoi(linia.c_str()) == starykod)
		{
			numerlinii++;
			continue;
		}
		else
		{
			*(tablica + (numerlinii - 1)) = linia;
			numerlinii++;
		}
	}
	kodzik.close();
	kodzik.open("kody.txt", ios::out);
	for (int i = 0; i < n - 1; i++)
	{
		if (i < n - 2)
			kodzik << *(tablica + i) << endl;
		else
			kodzik << *(tablica + i);
	}
	kodzik.close();
	delete[] tablica;
}

void ZmianaKodu(int kod, int nowykod)
{
	fstream kodzik;
	kodzik.open("kody.txt", ios::in);
	int n{};
	string linia1{};
	while (!kodzik.eof())
	{
		getline(kodzik, linia1);
		n++;
	}
	string* tablica = new string[n];

	int numerlinii = 1;
	string linia{};
	kodzik.close();
	kodzik.open("kody.txt", ios::in);

	while (getline(kodzik, linia))
	{
		if (atoi(linia.c_str()) == kod)
		{
			*(tablica + (numerlinii - 1)) = to_string(nowykod);
			numerlinii++;
			continue;
		}
		else
		{
			*(tablica + (numerlinii - 1)) = linia;
			numerlinii++;
		}
	}
	kodzik.close();
	kodzik.open("kody.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			kodzik << *(tablica + i) << endl;
		else
			kodzik << *(tablica + i);
	}
	kodzik.close();
	delete[] tablica;
}

void rickroll()
{
	system("cls");
	cout << ":////:::::::/osyyhhdmmmmmmmmmmddddddmdddddhhhyyyy+\n////::::::::/+oyyhddmmmmmmmmmmmddddmmmmmmdhhhhhhs/\n/////////////+oyyhdddmmmmmmmmmmmmmmmmmmmdhhhddhhs+\n/////////////+syyhddddddddmmmmmmmdddddhyysyyhhhhs+\n///::////////+shhhhhhhhhhhhhhddhhyyysoooooosyhhys+\n///://///////+shdhhyyyyyyyyyyyyysssooo+++++osyyso+\n/////////////+shhhyyyyyyyyyyysssssssooo++++osyys++\n////////:::///oyhhyyyyyyyyyyssssssssooooo++osyyo//\n//////::::::/+oyhhyyyyyyyyyysssssssooooooo++oys///\n:////::::::/+syyyyyyyyhhhhhyyyssyysssooooo+++so+//\n::::::::::::/osyssyyyyhhhhhhhhyyyyyhyyyysso++o+s+/\n:-::-::::::://yysosyyyyhhhhhhhysooyhyysoooo++oo+//\n:-:--:::::::::oyyosyyyyyhhhyyyyo+++ssysoo+++/oo///\n--------:--:--:syssyyyyyyyyyyyyo+++oooooo+++++////\n--------:--:--//+ooyyyyyyyyyyyyo++oooooooo++//::::\n--------------////+syyyyyyyhhyysooossooooo+/::::::\n----:--:--:--://///syyyyyyyyyyysoooossooo++/:::::-\n-------------:////:+yyyyhhhyyyysoooosssoo++s+/::::\n:--::-::--:--/////::oyyyyhhhhhhyssssyysoo++yhys+/:\n:::::-:::::::/+++///osyyyyyhhhhysssssssooo+odddhso\n::::::::::::/++++/+ssyyhhhhhhyyssssssssooo+odddddd\n::::::::::::/+++osyysyhhhhhhhhhyysssssssso+oddmmmm\n////////////ossyyhhsyhhhhhhhdddhhyyyyssyso+odmmmmm\n/////+++osyhhhhhhdyshdhhhhhhdddhhhyyyyysooosmmmmmm\n/+++osyhhdddmmddddsydddddhyyhddddhhhhysooooymmmmmm\noshhdddmmmmmmmmddmyyddddddhhhddddddhyssooosdmmmmmN";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "////::::::::::://oyyssssyddmmmmmmmmmmmmmmdhyhhys+/\n////::::::::::/oyhdhyyydmmmmmmmmmmmmmmmmmmddhhyhs+\n/////////////+shhddhhdddmmmmmmmmmdmmmddddddhyyyyys\n/////////////+oyyhdddddmmmmmmmmmmmddddhdddddhhhyys\n///://////////+shhdddddmmmmmmmmmmmmmdddddmmmmdhyys\n///://////////+shdddddddmmmmmmmmmmmmmmmmmmmmddhyys\n////////////++oyddddddddhdddddddmmmmmmdddddhyyhyyo\n////////:::/++oyddddhhyyyyyyyyyhhhhhhhyyssoooosyso\n/////::::::/+oshdddhhyyyyyyyyyssssysssooo++++osso+\n////:::::::/++shdddhyyyyyyyyyysssssssoooooo++osso/\n:::::::::::/+syhhhhhyyyyyyyyyyysssssoooooooo+oso//\n:::::::::::+yyyhhhhyyyyyyyyyyyyysssssooooooo++o///\n:::-:::::::/syyyhhyyyyhhhhhhhhhyyysssssoooo++++///\n-------::-::+yyyyyyyyyyyhhhhhhhhhhyyyyyyyyyso/////\n-:--:--:--:-:syyyyyyyyyyyhhhhhhhhysooyhyysoo+/::::\n----:--:--:--/syyyyyyyyyyyyyyhhhyyso+ossso++/:::::\n::-:::::--:--//++syyyyyyyyyyyyhhyys++ooooo++/::::-\n---:--:-----:///+oyyyyyyyyyyhhyyhysoooooooo//:::::\n::::-::--:::://++osyyyyyhhhhhhhhhysoosssoo+/::::::\n::::::::::::/+++/osyyyhhhhhhhhhhhysoosssoo////////\n::::::::::::/+++/+yyhhhhhhhhhhhhyysssyysso++//////\n::/::/::/::/+++++oyhhhhhhhhhhhhhhyyssyysohhs++++//\n///////////++oosysyhhhhhhhhhhhhhyyysssssohdddysoo+\n/////++++++oosyhsyhhhhhhhhhhhhhyyyyyssssoymmmmddhy\n++++++++osyhhhdhsydhddddhhyydddhhyyyyyysoymmmmmmmm\n++++osyddddddddyyhdhddddddyhddhhhhyyyhssohmmmmmmmN";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":///::::-::::::::::////:://///////////++++////////\n////:::::::::::::://///////////++ooooooo++////////\n///////////////////+++++++++osyyhhddddhhhyyso+++++\n//////////////////++++++oosyhhddhhdhhdddddddhso+++\n///:::://///:::///++++oyhhyyyhddddddddddddmmddhsss\n///::////////:::/+++oshyyyhdddmmmmmmdddmmmmmmddhsy\n///////////////:/+ossssyhdmmmmmmmmmddddmmmmdddddyy\n////////::::////+ohhyydddmmmmmmmmmmmdddmmddddddddh\n//////:::::://++ooyhdddddddmmmmmmmmmdddddddddddhhh\n::://::::::://+ossshdddddddddddmmmmmmdddddddddddhh\n:::::::::::://+ooyhddddddddddddddddmmmmmmddddddmdd\n::::-:::::::/+ssyhdddmmmmddddddddddddddddmmmmmmmmm\n::::-:::::::/syyhddddmmmmddddddhhhhhhhhhhhhddddddh\n-----:--::::/yhdddddmmmmmddddhhyyyyyyyyssoossyysoo\n--:--:--:--::ohdddddddddddddhhhyyyyyyysssooooooo++\n----:------:-/yyyhhddddddddhhhyyyyyyyyyssooooooo++\n-:::::-:--::-:oyyyyhhddddhhyyyyyyyyyyssssooooo++++\n----:--------:osyyhyyhhdhhyyyyyhhhyyyssssssooooo++\n::-::-::--:--/+syyyyyyyyhyyyyyhhhhhhhhhhhhysssssso\n:::::-:::::::/+oyyyyyyyyyyhhhyyyyyhhhyyhhhhssyys+/\n:::::::::::::+++oyyyyyyhhhhhhhhyyyssssssyyysosso//\n:::::::::/::/++++syyyhhhhhhhhhhhyysssssyyhysooo+//\n////////////+++o+syhhhhhhhhhhhhhhyysssyhhhhysso+++\n////////+//+oooo+syhhhhhhhhhhhhhhhyyyhhdhhhyssoo++\n/++//+//++++ooooosyhddddhhyyhhhhhhhhhhhdddhyysoooo\n+++++++++++ooossyyhhddddddhhddhhdddddddhhyyysooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":////:-:--::::::::://///://///////////++++////////\n:///::::::::::::::://///////////++oooooooo+///////\n///////////////////++++++++++oosyhhhhhddhhhyso++++\n//////////////////++++++++osshhddddddddhddddhhhyoo\n///:::://////::///++++++sydddhhhhdddddddddddddddhy\n///:://///////:::/++++oshdhhddddmmmmmmmmdddddddmdh\n//////////:////::/++oshhyyyddmmmmmmmmmmmddddmmdddd\n////////:::://///++shddhhddmmmmmmmmmmmmddddddddddd\n//////::::::///+++oshdddddmmmmmmmmmmmmmmdddddddddd\n::://::::::://++oshhhdddddddddddddddmmmmmdddddddhd\n:::::-:::::::/+ooyyhddddddddddddddddddmmmmmmdddddd\n:::::::::::::/oyyhdddmmmmmmdddddddddddddddddmmmmmm\n::::-::::::::/yhhdddmmmmmmmdddddddhhhhhhhhhhhddddd\n:-------::-::/yhddddmmmmmmmdddddhhhyyysssssooossyy\n--:--:--:---::yhdddddmmmmmmddddhhhyyyysssssooooooo\n-----:--:--:-:ohyyyhhdddddddddhhhyyyyyyssssoooooo+\n-::-::-:---:-:+ssyyyyhhdddddhhyyyyyyyysssssoooo+++\n----:--------:/syyyyhyyhhhhhhyyyyyyhyyssssssoooooo\n::-::--:--:--:/oyyyyyyyyyhhyyyyyyhhhhhhhyhhyysssss\n::-::-:::::::/++syyyyyyyyyyyhhhyyyyyyhhyyhhhhysyyo\n:::::::::::::/+++syyyyhhhhhhhhhhyyyssssssssyysos+/\n::::::::::::/++++syhyyhhhhhhhhhhhhyyssssssyyysoo+/\n/////////////++ooyyhhhhhhhhhhhhhhhhyysssyyhyysoo++\n/////////+//+ooosyhhyhhhhhhhhhhhhhhyyyyyhhhhyysoo+\n//+//+//++++ossyyhhhhddddhhyyhhhhhhhhyyhhdddhysooo\n+++++++++++shsyyhhhhhhdddddhhhddhhhhdddhhhhysooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":///::::-::::::::::////:://///////////++++////////\n////::::::::::::::////////////////////++++////////\n///////////////////+++++++++++++++++++++++++++++++\n//////////////////+++++++++++++osyyyyyhyysoo++++++\n///:::://///:::///++++++++oossyhhdddddddhdhhyssoo+\n///::////////:::/++++++++syhdddddddddddddddhhhhdhs\n//////////////::/++++++oshdddddddddmmmmmmmdddddddd\n////////:::://///+++++oyhddhhddmmmmmmmmmmmdddddddd\n//////:::::://++++osyhddddddmmmmmmmmmmmmmmdddddddd\n::://::::::://++++oshdddddmmmmmmmmmmmmmmmmdddddddd\n:::::::::::://++oshddddddddmmmdddddddmmmmmddddddhh\n:-::-::::::://ooshdmmmmmmmmmmmmmdddddddmmmmmmmdddh\n::::-:::::::/+shhdmmmmmmmmmmmmmmmddddddddddddddmmm\n-----:--::::/shddmmmmmmmmmmmddddddddhhhhhhhhhhhhdd\n--:--:--:--:+ydddmmmmmmmmmmmdddddhhhyyyyssssoooosy\n----:------:+hddddddmmmmmmmmddddhhhyyyyssssoo+++oo\n-:-:::-:--::+yhdddhhhhdddmdddddhhhyyyyyssssoooo+++\n----:-------/yhdhhyyyhhhdddddhhyyyyyyyyssssoooo+++\n::-::-::--:-:shdhyyyhhyhhddddhyyyyyyyyyssssooooooo\n:::::-:::::::+hdhyyyyhyyyhhhhhyyyyhhhhhyyyyyyyssoo\n::::::::::::/+shhyyyyhhhhhhhhhhhyyyyyyhhyyyhhysss+\n:::::::::/::/+oyhhhhhhhhhhhhhhhhhyyyssssssssysoo+/\n////////////+ooyhhhhhhhhhhhhhhhhhhyyysssssssysoo++\n////////+//+oosyhhhyhhhhhhhhhhhhhhhyyyssssyyyyso++\n/++/++//+oyhysyhhhhhhddddhyyhhhhhhhhyyysyhhhyysooo\n+++++++oydyyyyhhhhhhhdddddhhhdhhhhhhhyyyhhddhhysoo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "++++++/////++++++///////////////////////////++++++\n+/+++++++/+++++++//++++++++++///////////+/////++++\n://////////+++++++++++++/////+++++++++++++++++++++\n////:::::::/+++++///+++///////+++///+++++////////+\n//:::::://///++/+++++++///////++++++++++++///////+\n/::::////+/:/++/++//+osysyysso++//+++++++++++/////\n::////::///:/++///+shhhhddddddo/////++++//++++++//\n//////:://///++/:/shddhhyyhdddy//////++++/++//++++\n:/:://///:://++/::/syysoooshhhh+/////+++++++//++++\n-:///:://:::/+/////osyssooosyyy+////+++++///++++//\n/:///:::/:::++//+//oyysyysoooso++++++++++///////++\n://://:://:/++++////ssoyssosoo+++///+++++//+///+++\n//::///////++++/:/++oyysyssyys++++///++++//+//++/+\n/////+++////++++/++//+yysssyys++/++//+++++//++++//\n/////+++///++++++osyyssyyysssssohyso+++++///++++/+\n:::/+//++//+oosyhdmmmd+oyyys+o+odddddhso+///++++//\n:::/+//+++/shddmmmmmmdooosys+++hddmmmmmddyo+++/+/:\n/:/+//+++++dmmmmmmmmmmdhhyysssyddmmmmmmmmdh+++//+/\n+++++++++++dmmmmmmmmmmmhyyyyyhdmmmmmmmmmmmd+++++++\n++ooo+++++odmmmmmmmmmhyysyhhyhdmmmmmmmmmmmd++++ooo\n+ooo++++++ymmmNmmmmdyyyssyhhhdmmmmmmmmmNmmdo+++ooo\n+ooooo+++odmmNNmmmmyyhysyhhhhdmmmmmmmmNNNmmsoooooo\n+osooooooymmNNNmmdhhhhhhdddhhdmmmmmmmNNNNmmsoooooo\nossooooosdmmmmmmdmmdhdmmdddddmNmmmNNNNNNNNmsoooooo\nssssossssdmmmmNmmmmmmNNmdddddNNNmNNNNNNNNNmsssssoo\nssssssssymNNNNNNmmNNNNNmdddddNNNNNNNNNNNNNdsssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "++++++/////++++++///////////////////////////++++++\n+/+++++++/+++++++//++++++++++///////++++/////+++++\n://////////+++++++++++++////++++++++++++++++++++++\n///::::::::/++++///++o+oooo+/++++///+++++////////+\n//::::::////+++/++ooyhhhhhhhs+++++++++++++///////+\n::::////+//:/++/oshdddddddddds++/++++++++++++/////\n::////:////:/++/+yhddhysshdddy/////+++++//++++++//\n/////::://///++/:/syysooosyhhy+//////+++/+++//++++\n:/:://///::/+++/::osyyysooosss///////+++++++//++++\n-://:::/::::/+//+/+sysyysoooo++////+++++////++++//\n/////:::/::/++//+//ososysoooo+/++++++++++/://///++\n://///::/::/++++////syssssosoo+++///+++++//+///+++\n//::///////++++//+sydhyysssyyssohyso+++++/++//++/+\n/////+++///+++oshdmmmmyosysyyso+hddmmdhy+//+++++//\n/////+++///syhddmmmmmmdossssso+oddddddddh///++++++\n:::/+//++/sdmmmmmmmmmmmyssssoooydddddddmd+//++++//\n:::+///+++sdmmmmmddmmmmssyysssyhdddddmmmh+/++//+/:\n/:/+//+++++hmmmmmmmmmdhsyyysyyyhdmmmmmmms+++++//+/\n+++++++++++hmmmmmmmmdhdhhysyyhhhdmmmmmmmo+++++++++\n++ooo++++++hmmmmmmmmdmmmdhyhhhhhdmmmmmmdo++++++ooo\n+ooo++++++ohmmmmmNmmmmmmNmhhhhhddmmmmmmdo++++++ooo\n+oooo+++ooodmmmmNNNNNmmmmmdhhhdddmmmmmmhoooooooooo\n+osooooooosmmNNNNNNNNNmmmmddhdddmNNmmmmsoooooooooo\nossooooooosdNNNNNNNNNNNmmmmdddddmNNmmmdssooooooooo\nsssoosssooohmNNNNNNNNNNNmmmddddmNNmmmdssssssoooooo\nsssssssssssshmNNNNNNNNNNNmmdddmmNNmmdyssssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/ohho///////////////+ooooooooooooooooo+++++++//:::\n/ohy+///////////////+ooooooooooooooooo+++++++/::::\n/shy+///////////////+ooooooooooooooooo+++++++/::::\n/shy+///////////////ooooooooooooooooo++++++++/::::\n/shy//////::::://///ooooooooooooooooo++++++++/::::\n/shs/::::::::::::::/oooooooooooooooooooo+++++/::::\n/yhs/::::::::::::::/oooooooooooooooooooooo+++/::::\n/yhs/::::::::///////+oooooooooooooooooooooo+/:::::\n/yho/:::::://////////ooooooooooooooooooooo++/:::::\n/yho//::::://////////ooooooooooooooooooooo+/::::::\n+yyo////:://////////ooooooooooooooooooo+++/:::::::\n+yyo///////////////+ooooooooooooooooooooo++///::::\n+hyo//////////////+ooooooooooooooooooooooyy///::::\n+hyo////////+++++shsooooooooooooooooooosddh+///:::\nohyo///////++++shmmNdhyssooooooooooooshdmdhs////::\nohy+/////++++ohdmmmNmmmmmmmdddhhhhhdddmmmdds////::\nohs+///++ossyhddmmmmmmmmmmmmmmmmmmmmmmmmmmdy+/////\nshs+++oosyyhhdddmmmmdmmmmmmmmmmmmmmmmmmmmddh++++//\nshsoshddddddddddhdddddmmmmmmmmmmmmmmmmmmddhs++++++\nshssdmmmmddhhhhhhhddddmmmmmdddhhhhhhhyyssooo++++++\nyhsyddmddddddddddddddddddhhhyyyysssssoooooooo+++++\nyhsyhdddddddddddhhhhyyyssssssoooooooooooooooooo+++\nsysssssssyyysssssssssssoooooooooooooooooo+++++++++\nsssooosssossssssooooooooooooooooooooooooo+++++++++\nyysoooooososooooooooooooooooooooooooooooooooooooo+\nyyssssssssoooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///ohho/////+ooooooooooooooooooo+o+++/::::::::::::\n///odho/////+ooooooooooooooooooooo++++//:::::/::::\n///shy+//////+ooooooooooooooooooooo+++//::::::::::\n///shy+///////+ooooooooooooooooooooo+++//:::::::::\n///shy+////////++oooooooooooooooooooo++////:::::::\n///shs//////////+ooooooooo++oooooooo+++/////::::::\n::/yhs///////////oooooooooo++++o+++++++//////:::::\n::/yhs///////////+oooooooooo+++++++++++/////::::::\n::/yho////////////+oooooooooo++++++++++////:::::::\n://yho////////////+oooooooooooo++++++++os////:::::\n//+yyo////////////+oooooooooooooooooooohhs/////:::\n//+hyo////////////ooooooooooooooooooooymmho/////::\n//ohyo///////////+ooooooooooooooooooosmmmdy//////:\n//ohyo//++++++++ohhysoooooooooooosshdmmmmdho/////:\n//ohyo///++++++ohmmNmmmmddddddddmmmmmmmmmddy+////:\n//ohyo///+++++sddmmmmmmmmmmmmmmmmmmmmmmmmdhs+/////\n//ohs+//+++osydddmmmmmmmmmmmmmmmddmmmddhso+///////\n//shs++/+osyyhhddmmmmmmmmmmmmmdhyhhhhyso++++++++//\n++shs+oyhddddddddddddmmmmmmddhhhhhhyyyyoooo+++++++\n++shsohmmmmddhhhhhddddmmmmdhhyyyyyyyssooooo+++++++\n+oyhssddmddddddddddddddhhhyssssssoooooooooooo+++++\n+oyysshhddddddddhhyyyssssooooooooooooooooooooo++++\nooyyssssssssssssssoooooooooooooooooooooo++++++++++\noosysoosssssooooooooooooooooooooooooooooo+++++++++\nosyyssooooooooooooooooooooooooooooooooooooooooooo+\nssyyyssooooooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///ohho+ooooo++++++oooooooooo+++++//::::::::::::::\n///sdyo/+oooooo++++oooooooooooo+++//::::::::::::::\n///shy+/+oooooooo++ooooooooooooo++//::::::::::::::\n///shy+//+oooooooooooooooooooo++++//::::::::::::::\n///shy+//++oooooooooo++++o++++++++///:::::::::::::\n///yhs////+oooooooooooo+++++++++++////////::::::::\n::/yhs/////+ooooooooooooo+++++++++++//////::::::::\n::/yhs//////oooooooooooooo+++++++++yo/////::::::::\n::/yho//////+ooooooooooooooo++++++odho////::::::::\n//+yyo///////+ooooooooooooooooooo+ymdh+///::::::::\n//+hyo////////oooooooooooooooooooodmddy////:::::::\n//+hy+////////+oooooooooooooooooyhddddhs/////:::::\n//ohy+///++++++ooooooooooooosyhddddmmddho////:::::\n//ohy+//+++++++hhyssssssyhdddddmmmmmmddy+////:::::\n//ohy+///+++++hmmmmmmmmmmmmddmmmmmmdhs+//////:::::\n//shs+/+++++ohddmmmmmmmmmmddmdysssso++////////::::\n//shs+/++++yhddmmmmmmmmmmdddhso+++++++++++////////\n/+shs++++oyyhhddmmmmdddddddhysssoo+++++++++++/////\n/+yhs+++shhhddddmmddddddddhyyyysoooooo++++++++++++\n++yhsoosdmmmmddhdddddddddhysssooooooooo+++++++++++\n+oyhsoshdmmmddddddddhhhysoooooooooooooooo+++++++++\n+oyysosyddddddhhhyyssoooooo+oo++++++++++++++++++++\nooyysoossyyysssooooooooooooooooo++++++++++++++++++\nosyysooooooooooooooooooooooooooooooooo++++++++++++\nosyysooooooooooooooooooooooooooooooooooooooooo++++\nssyysooooooooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "//////+hhs////////////++oo++++///+++++++++++//::::\n//////+hho////////////++oooo+++//++++++++++++/::::\n//////ohho/////////////++oooo+++/++++++++++++/::::\n//////ohyo/////////////++++++++++++++++++++++/::::\n//////ohy+/////////////++++++++++++++++++++++/::::\n//////ohy+////:///////++++++++++++++++++++++//::::\n:::::/shy+////:://///+++++++++++++++/+++++++/:::::\n:::::/shs////////////oooooooooo+++++++++++++/:::::\n:::::/shs////////////oooooooooooo+++++++++++/:::::\n//////yhs////////////ooooooooooooooo++++++++/:::::\n//////yhs////////////+oooooooooooooooo++++++/:::::\n/////+yyo+///////////+oooooooooooooooooo+++++/::::\n/////+yyo+//++++++++++oooooooooooooooooo+++oo//:::\n/////+yyo+//+++++++++osoooooo+++ooooooooo+oyy//:::\n/////+yyo+//+++++++oydmdysoo+++++++ooooooshhy+//::\n/////oyyo+///++++shdddmmmdhssooooooossyhddddy+////\n/////ohyo+///++syyhddddmmddhhdddddddmmmmmdddh+++//\n/////ohy+++++oyyyhyhddddddddhdmdddmmmmmmmddhs+++++\n/////ohs++++shhhhhhddddddddddddddddhhhhyysoo++++++\n/////shso+oydmmmdddddddddddddddhhysssooooooo++++++\n//+++shsoosdmmmmddhdddmmmmdddhyssoooooooooooo+++++\n+++++shsosyddmmmdddddddddhhyssooooooooooooo+++++++\nooooosysoosyyhhhhhyyyyysssooooooooooo+++++++++++++\nooooosysoooossssssssssssoooooooooooooooooo++++++++\noooosyyssoosssssssssoooooooooooooooooooooooooooooo\nsssssyyyssssssssoooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////+hhs/////////////++++++++oooo++++++/:::::::\n///////+hhs/////////////+++++++oooooo+++++//::::::\n///////+hho/////////////++++++ooooooo++++++/::::::\n///////ohyo/////////////+o+++++oooooo++++++/::::::\n///////ohy+////////////+o++++++ooooo++++++++/:::::\n///////ohy+////:///////++++++++++++++++++++//:::::\n:::::::shy+////:://///+oo++++++++++++++++++//:::::\n::::::/shy+//////////+oooooooo++++++++++++///:::::\n::::::/shs///////////+ooooooooooo+++++++++++/:::::\n:::/://yhs////////////ooooooossooooo++++++++//::::\n///////yhs////////////+oooooooooooooo++++++++/::::\n//////+yhs+///////////+oooooooooooooooo++++++o/:::\n//////+yyo+///////////+ooooooooooooooooo++++ss//::\n//////+yyo+/+++++++++++ooooooooooooooooooo+shy/:::\n//////+yyo+/++++++++oyddyoooooooooooooooosyhhy+/::\n//////+yyo+///++++oyddmmmmhysssooooossyydddddy+//:\n//////oyyo+///++oyhhddmmmmmmmmmmdddddmmmmmdddho///\n//////ohy+++++oyyhhyhdddmmmmmmmmddmmmmmmmmddhyo+++\n//////ohy++++syhyhhhddddddddmmmdddddddddhyysoo++++\n//////shso+oydmdddddddddddddmmmddhyysssoooooo+++++\n///+++shsoosdmmmmddhdddmmmddddddyssssoooooooooo+++\n++++++shsosyddmmmdddddddddhhyysssoooooooooooooooo+\noooooosysoosyyhhhhhyyyyysssoooooooooooooooooooo+++\noooooosysoooosssssssssssoooooooooooooooooooo++++++\nooooosyyssoossssssssoooooooooooooooooooooooooooooo\nssssssyyysssssssssoooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////yhy+/////+oooooo++++oooooooo+++++//::::::::\n//////+hhy+/////+ooooooooooooooooooo+++++/::::::::\n//////+hhs//////++oooooooooooooooooo++++///:::::::\n//////+hhs///////+ooooooooooooooooo++++////:::::::\n//////+hho///////++oooooooooooooooooo+///:::::::::\n//////+hyo////////+ooooooooooo++ooooo+//::::::::::\n::::::+hy+////////+ooooooooooo+++++++++////:::::::\n::::::ohy+/////////ooooooooooo++++++/+++++/:::::::\n:::::/ohy+/////////+ooooooooooooo+++++++++/:::::::\n:::::/shs+//////////oooooooooooooo++++++++//::::::\n//////shs+//////////+ooooooooooooooo+++oo++o/:::::\n//////shs+///////////ooooooooooooooooo++ooyy+/::::\n/////+yhs+///////////+ooooooooooooooooo+oyhho///::\n/////+yhs+//+++++++++ooooooooooooooooooshddhs///::\n/////+yhs+//+++++++ohddhyssooooosssyyhdddddhy/////\n/////+yyo+///++++syddmmmmmmmmmmmddddddmmmmdhy+////\n/////+yyo+///++syhddddmmmmmmmmmmddmmmmmmmdddho////\n/////oyyo++++oyyyyhhddmmmmmmmmmddmmmmmmmmddhs+++//\n////+ohyo++oydhhhddddmmmmmmmmddddddhhhhyysoo++++++\n////+ohyooohmmmmmdddddmmmmmmmmdhyyssssooooooo+++++\n+++++shyoosddmmmddddddmmmmmmddysssssooooooooooo+++\n+++++shsosshdddddddddhhhhhhyysssssssssoooooooooooo\nooooosysooosyyyyyyyssssooooooooooooooooooooooooooo\nooooosyssooosssssooooooooooooooooooooooooooooooooo\nooooosyssooooooooooooooooooooooooooooooooooooooooo\nsssssyyysssooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////sdho/////////+oooooooooooooooooo++++///::::\n///////sdy+/////////+oooooooooooooooooo++//////:::\n///////shy+//////////ooooooooooooooooo++//////::::\n///////yhy+//////////ooooooooooooooooo++////::::::\n///////yhs///////////oooooooooooooo++++++/::::::::\n::::://yhs//////:////ooooooooooooooo++++////::::::\n::::::/yhs//////:////+ooooooooooooooo++//////:::::\n::::::+hyo/://///////+oooooooooooooooo++++++//::::\n:::::/+hyo////////////ooooooooooooooooo+++++//::::\n//////+hyo////////////oooooooooooooooooo++o+/:::::\n//////ohyo////////////+ooooooooooooooooooo+++/::::\n//////ohy+/////////////oooooooooooooooooo+oyy////:\n//////shy+///+++++++++sddhyyssoooooooooosyhhy+////\n//////shy+///++++++osdddmmmmmmmddddhhhdddddhho////\n//////shs+///+++oosyhhdmmmmmmmmmmdddddddddddho////\n//////shs+///+yhdddddddmmmmmmmmddddmmmmmmmdhho////\n/////+yhs+//+hdmmmdddddmmmmmmmdddmmmmmmmmdddhs////\n/////+yyo+++oyyhhhhhhddddmmmmmdddmmmmmmmmddhso+///\n///+++yyo+++ooossssyyyhhhhddddddddhhhhhyyssoo+++++\n/++++oyyooooooossssyyyhhhhddddhhyysssoooooooooo+++\n+++++oyyoooooosssyyyyyyhhhhhhysssssoooooooooooooo+\n+++++oyyoooooooosssssssssssssooooosooooooooooooooo\nooooosyysooooooossssoooooooooooooooooooooooooooooo\nooooosyssooooooooooooooooooooooooooooooooooooooooo\nooooosyysooooooooooooooooooooooooooooooooooooooooo\nsssssyyyssoooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////yhy+////////////+ooo+++++++ooooooo+++++++/:\n///////hhs/////////////+oooooo+++ooo+oooo+++++++/:\n//////+hhs/////////////ooooooooooooo++ooo+++++++/:\n//////+hhs////////////+ooooooooooooooo++o+++++++/:\n//////+hho////////////ooooooooooooooooo++++++++//:\n:::///+hyo/////://///+oooooooooooooooooo+///+++//:\n::::::ohy+/////://///+ooooooooooooooooooo+///+//::\n::::::ohy+/://///////+oooooooooooooooooooo+//+//::\n///::/ohy+////////////oooooooooooooooooooo++++//::\n//////shy+////////////oooooooooooooooooooo++++/:::\n//////shs+////////////+oooooooooooooooooooo+++/:::\n/////+yhs+/////////////oooooooooooooooooooo++//:::\n/////+yhs+///+++++++++/+yyyssoooooooooooo+++o///::\n/////+yhs+////++++++++odmmmmmddhhyysssooossyy+///:\n/////+yhs+//////++++shdmmmmmmmmmmmmdhdddddhhy+////\n/////+yyo+/////+++syddddmmmdddmmmdddddmmmddhy+////\n::://+yyo////+++osyyhhddddmmdddmdddmmmmmdddhho////\n:////+hyo//+++oyhhhhddddddddddddddmmmmmmmddhs++///\n/////ohyo+++oohdmmmdddddmmmddddddddhhhyyysoooo++++\n/////shyoooooshdddddddddmmmdddddhysssoooooooooo+++\n+++++shsooosssyhhhddddddddddhhhhysosooooooooooooo+\n+++++shsooossssyhhhhhhhyyysssooooooooooooooooooooo\nooooosysoooooosssssssssooooooooooooooooooooooooooo\nooooosyssoooooossssooooooooooooooooooooooooooooooo\noooosyyssooooooooooooooooooooooooooooooooooooooooo\nsssssyyysooooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////ydy+/////////////++++////////+++++++++++/::\n///////yhy+/////////////+o+++///////+++++++++++/::\n///////yhs+/////////////+o+++++/////+++++++++++/::\n///////yhs//////////////++++++++//////+++++++++/::\n///////yhs//////////////++++++++++/////+++++++//::\n/:::::/hho//////://////+oo+++++++++++////+++///:::\n//::::+hyo//////://///ooooooooooooo+++/////////:::\n//////+hyo/://///////+oooooooooooooooo+++///////::\n//////ohy+////////////oooooooooooooooooooo++////::\n//////ohy+////////////+oooooooo+++++++++++o+++//::\n//////ohy+/////////////ooooo+++++++++++++++++++/::\n//////shy+/////////////+ooo+++++////+++oooo+++/:::\n//////shy+////++++++++++osoo++++/////++ooo+++///::\n//////shs+////+++++++++ohmmmdhso++++++oooooos+///:\n//////shs+//////+++++oydmmmmmdhhdddhhyyyyhhhh+///:\n:::///shs+//////+++oyddddmmmddhddmmdddddddddho////\n:::::/yyo+/////+++syhhhdddmmddhhdddddmmmmdddhs+///\n://///yyo////+++oyyyyhhdddddddddddddmmmmmddhso++++\n/////+yyo++++++ohddddddddmmdddddddddhhhhysoooo++++\n/////oyyo+oooooymmmmmddddmmmmdddddysssooooooooo+++\n+++++oyyooooosshdddddddddddddddhhsoooooooooooooo++\n+++++oyyooossssyhhddddddddhhyysooo+++++ooooooo++++\nooooosyssooooosssyyyssssssoooooooooooooooooo++++++\nooooosyssooooooosssssoooooooooooooooooooooooo+++++\nooooosyysooooososooooooooooooooooooooooooooooooooo\nsssssyyysooooooooooooooooooooooooooooooooooooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::::/++++/////////+++///////++++++//++/////\n////////////////////+++++++//////::/+++++/////////\n::/:::::://////////+++++/:::://////+++++++++///::/\n///::::::::://///::////::::::://////+++++//::::-:/\n//:::::::///////////////::::::://///+++++///:::-::\n::-:://///::://///:::////:::://////++/+++/++//::-:\n:::///:::/:-:///:--:::///+ooo++::::/++++///++///::\n/////::::/:::///----::/+oshhhhys+:::/+++//+////++/\n://://///:-:////:---::/sssssyyhhs/::/++++//+//////\n::///:://:::///://:::+ossso+++oyo::/+++++::///////\n/////:::/:::////////+o+osssoooos+//++/+++:::/::/++\n://///:://::////::::+++ooooooo+//::/+++++/:/:::/++\n/+/:/+//////++/:::/++ooossooo++///////+++//+/:////\n/+++++++/::/+++//+os+sssysoo++////+//+++++//+++//:\n++//++++///+ssyhdddyosssooo+//////+++++++////++///\n////++/++shddddddmms+ssso++shs+////++++++///++//::\n///++//+odddmmdddmmyooooo++hdddhs+++//+++//++/:/:-\n+//++/++ydmmmmdddmmddyssoshdddddddy++++++++++/::/:\n++++++++hmmmmmmdmmmmdyssyhdddddddddo++++o+o+++/://\n+oooo++sdmmmmmmmmmmmmhyyydddmmmmmmdo+++oooo+///+++\n+ooo++odmmmmmmmmmmmmmdyyhdmmmmmmmmd+++ooooo+////++\n+ooooohmmmmmNmmmmmmmmdhhhdmmmmmmmmhoooooooo+++++oo\noosooymmmmmmNmmhdmdddmhhhdmmmmmmmmhoooooooooo+oooo\nossoohmmmmmmmdyyyhddmmdhddmmmmmmmmyoooooosoosssoos\nssssosmmmmmmdyyhdmmmmmdddmmmmmNmmmyoooossssoossoss\nssssssydmmmmmddmNNNmmmdddmmmmNNNmmhsssssssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "//////:::::/+++++////////+++/:/:////+++++//++/////\n///////////+////////++++++////////:/++++++////////\n:://::::://////////++/++/:::://////+++++++++///::/\n///::::::::://///:://+/::::::://////+++++//::::-:/\n//:::::::///////////////::::::://///+++++///:::-::\n::-:://///::://///:::/+++sssoo+/://++++++/++///:::\n:::///:::/:-:///::-::/osshhhhhyo/::/++++///++++//:\n//////:::/::////:---:/yyssssyyyy/:://++++/++///+++\n://://///:::////::-::oyssso+++so//://++++//+//////\n::///:://:::///://::+oossssosoo+/::/+++++/:://////\n/////:::/:::////////+oosossoo+/////++/+++/::/::/++\n/////+/://:/++///::/+osossoo+////::/+++++/://::/++\n/+///++////++++//+syossosso+/++//+////+++//+/:/+//\n/+++++++/:/+osyhddddosssssooo++///++/+++++//+++///\n++//+++++shdddddddmdoossoo+sdhyo//+++++++////++///\n////++++sdddmdddddmdoooo+++hddddhy++++++++//++//::\n///++//+hdmmmdddddmmdysssohddddddds+//++++/++/:/:-\n+//++/+odmmmmmdddmmmdyssyydddddddds++++++++++/::/:\n+++o+++ydmmmmmmmmmmmmhssyyddddddmms++++oo+++++////\n+oooo+sdmmmmmmmmmmmmmhsyyhddmmmmmms++++oooo+///+++\n+ooo+ohmmmmmmmmmmmmmmdyhhhdmmmmmmmo+++ooooo+////++\n+ooosdmmmmmmmmmmmmmmmdhhhddmmmmmmdoooooooooo++++oo\noosoymmdmmmmNmmNNmmmmdhhhdmmmmmmmyooooooooosooooss\nossoymmmmmmmNNNNNNmmmdhhhdmmmmmmmdyooooossoossssos\nsssshmmdhyhddddNNNNmmmddddmmmmNNmmdssssssssosssoos\nssssydhyyyhhdmmNNNNNmmmddmmmNmNNNNNmhsssssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////::://+++++////////+++///////++++++//++/////\n//////////////+/////+++++++/////////++++++///:////\n:://:::://////////+++/++/::::////+++++++++++////:/\n///::::::::://///:://+/+oso++////////++++///:::--/\n//:::::::///////////+ooshhhhhyo////++++++///:::--:\n::-:://////:://///::/syyysyyyys////++/++++++///:::\n:::///:::/:-:///::::+ysssoo++os//::/++++///++++//:\n//////:::/::////:-:/osssssoooo+//:://++++/++///++/\n://://///:::////::::oossssooo+//::://++++//+//////\n::///:://::://///////ossssoo+++/:::/+++++/:://////\n/////:::/::://///+ssossssoo+///////++/+++/::/:::++\n/////+/:////+osyhdddsssoss+///////:/+++++/://::/++\n/+/:/++/+oyhhdddddddy+osys+yys++/+////+++//+/:/+//\n/+++++++odddddddddddy++oso+hdddy++++//++++//++++/:\n++//+++ohddddddddddddysoooydddddy/++++++++///+++//\n////+++hdmmmmmdddddddhso+ohdddddy//+++++++//++//::\n///+++shdmmmmmmmddddddsssshdddddy++++/++++/++/://-\n+//++ohhdmmmmmmmmmmmmdsssyhddddds+++++++++/++/::/:\n+++o+ydmmmmmmmmmmmmmmdssyyhdddddo++++++ooo++++////\n+ooosdmmmmmmmmmmmmmmmdyyyhdmmmms+o+++++oooo+///+++\nooosdmmmmmmmmmmmNNmmmmhyhhdmmmmho+++++ooooo+////++\n+oosdmmmmdmmNNNNNNNmmmhhhdmmmmmmhsoooooooooo++++oo\nooshmmmmdhmNNNNNNNNNmmdhhdmmmmmmmdhsooooooosooooss\nosymmmmmdmNNNNNNNNNNNmddhdmdmmmNNNNmysooosoossssos\nssdmmmmmmNNNNNNNNNNNNmhhhmmdmNmmNNNNmdyssssssssoos\nsymmmmmmNNNNNNNNNNNNNmyyhyhdmNmhyhmNmdhhhhhhyyssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////::///+++++////////+++////////+++++///+/////\n////////////+//+////++++++++/////////+++++//:::///\n:://:://///////////+++osssso+////++++++++++/////:/\n:///:::::::::////::+oshhddhhho///////++++///:::--:\n//::::::://////////+yyysssssso/////+++++++//:::--:\n/:-:://////:://////+yyssoo++oo+////++/+++++++//:::\n:::://::://::///:::+ssssssooo///:::/+++++//++++//:\n//////:::///:///:-:+osssssoo+://::::/++++//+///+++\n://://////:://///:::+sssssoo+///:::://++++/+////+/\n::///:://::://////+sossssoo//+++/::/+++++//:////+/\n//////:://::/++osyddhossso+////////++/+++/::/:::/+\n/////+///++oyhddddddds+oss+syo+//////++++//:/::/++\n/++://+//odddddddddddh+oys+ydddo+++///++++///:/+//\n/+++++++ohddddddmmmdddhssssdddds//++//++++//++++/:\n++//+++oddmmmmddmmmmdddsoosdddd+///+++++++///+++//\n////+++hdmmmmmmmmmmmdddhoosdddy////+++++++//++//::\n////++sddmmmmmmmmmmmmdddsssdddy//++++/++++//++::/:\n+//++odmmmmmmmmmmmmmmmddysydddh+++++++++++/+++::/:\n++++sdmmmmmmmmmmmmmmmmmmhyhdmdy+++++++++oo++/++///\n+oosdmmmmmmmmmmmmmmmNNmmhyhmmmyooo+++++oooo+///+++\nooohmmmmmmmmmmmmmmmmNNNmhhdmmmdys+++++ooooo+////++\n+oydmmmmhmmmmNmNNNNNNNNmdddmmmmmdyoooooooooo+++++o\nosdmmmmhsdmmNNNNNNNNNNNmddmmdmmmNmdyoooooossooooss\nsdmmmmhsydmNNNNNNNNNNNNNdhdmdmmmNNmhyysssssossssos\nhmmmmhssdmNNNNNNNNNNNNNNdhyhdmmmyhdhhhhyyyysosssos\nmmmmhsshmNNNNNNNNNNNNNNNdhyydmNmsssssssysyysssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "//////::///+++++////////+++////////+++++//////////\n//////////////+////++++++///////////+++++/::://///\n://::////////////++++oo+/:::////++++++++++/////://\n///:::::::://///:+syhhhhyo/::///////++++//::::--/:\n/:::::::////////+syhhhyysy+:://///++++++///:::--:/\n:-:://////::////+yyssoo++oo://////++/+++/+++/:::::\n::///::://::///:/yssssoooo+///::::/+++++//++////::\n/////:::///////::osssssoo++/:/:::::/++++/++///+++/\n//://///:::////::+ossssooo+////::://+++++/+/://+//\n:///:://:::///////+ssssoo+//++//::/+++++/::///////\n////::://::/+///+shssssoo+////////++/+++/::/::/++/\n////+//////+++oyhddhoossooohyo/////+++++/://::/+++\n+/:/++/++++sydddddddy+sys++ddds/+////++++/+/:/+//+\n+++++++/+hdddddddddddssso+ydddo//++//++++//++++/:/\n+//+++++yddddddmddddddsoosyddd+//++++++++///++////\n///++++sdmmmmmmmmdddddy+ssyddd+///+++++++//++//:::\n///++/+hdmmmmmmmmmdddddssssddd+/++++/++++/+++::/:-\n//++/oydmmmmmmmmmmmddddysssddh+++++++++++/++/::/::\n++o+odmmmmmmmmmmmmmmmddhysyddh+++++++++oo++/+////:\nooosdmmmmmmmmNmmmmmmmmdhdyhmmsooo+++++oooo+///++++\nooohmmmmmmmmNNNmmmmmmmmhmhdmmho++++++ooooo+////+++\noosdmmmmmmmNNNNNNmmNNNmdmddmmmdsooooooooooo++++ooo\noymmmmmmmmmNNNNNNNNmNNmdmmmmmmmmhsooooooossoooosss\nymmmmmmydmmNNNNNNNmmmNmdNmmmmmNmdhyssssssoossssoss\ndmmmmmysdmmNNNNNNNNNNNmmNNmmNmmmhhhhhhysssoossooss\nmmmmmysymmNNNNNNNNNNNNmmNNmmmmyssssyhyssssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////::///+++++////////++////////++++++//+//////\n///////////+////////++++++//////////+++++//:::////\n::/:::////////////++++++/::://///++++++++++///////\n///:::::::::///////+++//:::::///////++++///::::-:/\n/:::::::://////+osyyyyso/::::://///++++++//::::-:/\n::-:://///::///shhhhhyyyo::://////++++++/+++//::::\n:::///:://:-//+syyssoo+os//////::://++++//+++///::\n/////:::///:///ssssoooooo+//::/:::://+++//+////++/\n:/:://///:::////sssssoo+++++///:::://++++//+///+//\n:////:://:::////oosssooo+///+++/:://+++++/:////+//\n///+/:::/::://///+osssoo+/////////+++/+++:::/::/+/\n////+/::+///+++//osyssoss+syyso+////+++++/:/:::/++\n/+///+//++++++++ydhssssys++hddddo+///++++//+::/+//\n++++++++/://+syddddhoooss+/hddddo++//+++++//+++/:/\n++//++++//oyhddddddds++oo+ohdddd+/+++++++///+++///\n///+++++ohdddddddddddysoosshdddh//+++++++///++//::\n///++//+yddddmmmddddddyssssydddh/+++/++++//++/:/:-\n+//+++++hmmmmmmmmddddddysssydddh+++++++++++++/::/:\n++++++++ymmmmmmmmmdddddhsssydddy+++++++oo++/++/://\n+oooo++odmmmmmmmmmmmmmdhysyymddyo++++++oooo+///+++\noooo++odmmmmmNmmmmmmmmmddyyhmmdds+++++oooo+////+++\n+ooooohmmmmmNNNNmmmmmmmddhydmmmmmsooooooooo+++++oo\nooooosmmmmmmNNNNNNNNNNmdddhdmmmmmmyoooooosssooooss\nossooymmmmmNNNNNNNNNNNNdmmdmmmmNNmhyssssssoosssoss\nsssssdmmmmmNNNNNNNNNmNNdmmmmmmmmmmdhhhyssssosssoss\nssssymmmmmNNNNNNNNNNNNNdNNmdmmmyyhyyhhysssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////::///+++++////////++////////++++++//+//////\n///////////+////////++++++///////://+++++//:::////\n::/:::////////////++++++/::://///++++++++++///////\n///::::::::://///://++/::::::://////+++++//::::-:/\n//::::::://////////+++//:::::://///++++++//::::-:/\n::-:://///:://+ossssss++/:::://///++++++/+++//::::\n:::///:://:-/oyyhhhyyhy+///////::://++++//+++///::\n//////::///:/oyyysooosys////::/:::://+++//+////++/\n://://///:::/+sssoooooss/+/////:::://++++//+/:////\n:////:://::://+sysooo+oo+////++/:://+++++/:////+//\n///+/:::/:::///+sssoo+o+//////////+++/+++/::/::/+/\n////+/:://:/++++ossooooso///////////+++++/:/:::/++\n/+///+////++++///osssooyssyhhhhyyo///++++//+/:/+//\n++++++++/::/++++sysyyssss+ydddddddo//+++++//+++///\n++//++++//:/+oshddsossooo/sdddddddh++++++///+++///\n////+++++//sydddddho++oo++yddddddddo+++++///++//::\n///++//+oyhddddddddhsssssssdddddddds+/+++//++/:/:-\n+//++/++sddmmmmddddddyssssshddddddmy+++++++++/::/:\n++++++++hmmmmmmmdmddddyyssyhdddddmmdy+++o++/++/://\n+oooo+++ymmmmmmmmmmmmddyssyhdddddmmmdo+oooo+///+++\nooooo+++smmmmmmmmmmmmmmhyyyhdmdmmmmmms++ooo+///+++\n+ooooo++hmmmmNNmmmmmmmmdyyhhdmmmmmmmmhooooo+++++oo\noosooooodmmmmNNNmmNmmmmddyhhdmmmmmmmmmyoooosooooss\nossooossdmmmNNNNNNNNNmmddhhhdmmmmmmmhhhsoooossssss\nsssssssymmmNNNNNNNNNNNmdmmdddmNmmmdyhhhysssosssoss\nssssssshmmNNNNNNNNNNNNNdmmmmdmmmmmmsyhyyssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "///////::://+++++////////+++///////++++++/////////\n///////////+///+////++++++//////////++++++/:::////\n:://::/://////////++++++/::::////++++++++++///////\n///::::::::://///://++/::::::://////+++++//::::-:/\n//::::::://////////+++//:::::::////++++++///:::-::\n::-:://////::///+ooo++++/:::://///++++++++++//::::\n:::///:::/:-:/+syhhhyyys///////::::/++++///++////:\n//////::///://oyhyysosyh+///::/:::://++++/++///++/\n://://///::://+sssooo+syo+/+////::://++++//+/:////\n::///:://::://+osssosooso////++/:://+++++/:://////\n///+/:::/:::///+sssooooo+/////////+++/+++/::/::/++\n/////+/:////+++/ossooooso+//////////+++++/://::/++\n/+/:/+/////++++/:+ssoooyyo+++ooo+++///+++//+/:/+//\n/+++++++/::/++++/+syyssssoyddddddddy+/++++//+++///\n++//++++//:/+++oyhsssssoo+odddddddddy+++++//+++///\n////++/++///+shdddhooooo+/odddddddddds++++//++//::\n///++//+++oyhdddmmdyoosssosdddddddddddo+++/++/://-\n+//++/+++sddddddmmmmdyssssyhdddddddmmmdyo++++/::/:\n+++o+++++hdmmmmmmmmmmhysyyyhdddddddmmmmmds+++++///\n+oooo+//+hmmmmmmmmmmmdhyyyyhddddddmmmmmmmy++///+++\n+ooo+++++hmmmmmmmmmmmmdhyyhhdmdddmmmmmmmmdo+///++o\n+ooooo+++ymmmmNNmmmmmmmdyhhhhmmmmmmmmmmmmmso++++oo\noosoooooohmmmmNNNNNmmmmdhhhhhdmmmmmmmmmmmmyoooooss\noosooossohmmmNNNNNNNmmmddhhhhdmmmmmmmhhhhdyoosssos\nssssssssymmmNNNNmmNNNNmdddddddmmmmmmmhhyydhoossoos\nssssssssymmmNNmhNmNNNNNmmmddmmmmmmmNmddhyyssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::::/++++/////////++///::///++++++//++/////\n////////////////////+++++///////////+++++//:::////\n::/:::::://///////++++++/::::////++++++++++////://\n///::::::::://///::/++/::::::://////++++///::::-:/\n/::::::::///////////++//:::::://///++++++///:::-:/\n::-:://///:::////////++//:::://///++++++/+++//::::\n:::///:::/:-:////+osyyysso/////::::/++++//+++/+//:\n/////::::/::////+yhhyysshy+/::/:::://+++//+////++/\n://://///:::////+sssoo++syo+///:::://++++//+///+//\n::///:://:::///:+osssooooso//++/:://+++++/:////+//\n///+/:::/::://///+sssooooo+///////+++/+++/::/::/+/\n////+/:://:/+/////ossoosso//////////+++++/:/:::+++\n/+///+/////+++/:::+sssosyo///+++++///++++//+//++//\n++++++++:::/+++//+++syssys+ssoo++++///++++//+++///\n+///++++/::/++++++++yysoos+oddddddhhys+++///+++///\n////++/++/:/++++oyhoosso+o/oddddddddddy++///++//::\n///++//++/:/+syhddmyoooss++yddddddddddd++//++/:/::\n+//+//++/+/yhdddmmmdhyssyssydddddddddddh+++++/::/:\n+++o+++/++odddmmdmmmmdyyyssyddddddmdmmmds++++++/+/\n+oooo+///+sdmmmmmmmmmmhyyyyyddddmmmmmmmmdso+//++++\n+ooo+++/++smmmmmmmmmmmdyyyhhdmdmmmmmmmmmmmyo++/+oo\n+oooo++++oymmmmmmmmmmmmhyhhhdmmmmmmmmmmmmmmy++++oo\noosoooooooymmmmmmmmmmmmdhhhhdmmmmmmmmmmmmmmyooosss\nossooosoo+hmmmmNNNmmmmmmhhdhddmmmmmmmmmmmmmyooooos\nossoossooohmmmmmNmmmdddmddddddmmmmmmmmddmmmhsssoss\nsssssssssshmmmmmmmhhhydmddddddmmmmmNdhhyhmmyssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::://++++/////////++/:/:////+++++///+//////\n///////////////////++++++///////////+++++//:::////\n://::::://////////++/++/:::://///++++++++++///:://\n//::::::::::////:://+//::::::///////++++///:::--:/\n/:::::::///:////////++/:::::::////+++++++///::--:/\n:-:://////:://////://+oo+//://////++/+++/+++//::::\n::///::://--///:::/osyhhhyyo//:::://++++//+++///::\n/////:::/:::///:--/syyyssoyh/::::::/++++//+////++/\n:/://///::-:///:::+ssoooo+oyo//:::://++++//////+//\n:///:::/::-://://:/osssoooooo++/::/+++++/::////+//\n/////:://::////////+ossooo+++/////++++++/::/:::/+/\n////+/::/:://///:::/ossoooo+////////++++/::/::/+++\n//://+/////+++/::/+++oossoo++++/++///++++/+/:/+//+\n++/++++/::://+///++///sssooo+hysso+//++++//++++///\n+///+++/:::/++++++//++soosso/yddddddhyso+///+++///\n////+/++/:/+++//+osyh++o+s+/odddddddddddo//+++//::\n///+///++//++++oyhdddsssssoohdddddddddddy/+++/:/:-\n///+/++////+++hdddmmmddyyyyydddddmmddmddd++++/://:\n++++++//++++++ddmmmmmmmyyyyhdddddmmmmmmddo++++//+/\n+ooo++///++++oddmmmmmmmhyyyhddddmmmmmmmmmho+//++++\n+oo+++///++++odmmmmmmmmdhhhhddmmmmmmmmmmmds++/++oo\n+oooo+++++oooodmmmmmmmmdhhhhdmmmmmmmmmmmmmdo+++ooo\nooooso+ooooooodmdhmmmmmdhhhdmmmmmmmmmNmmmmmhooosss\nossoosoo++ooooyyyydmmmmdhhhddmmmddmmmNmmmmmyooooss\nsssosssoooosssyhyyhmNNmmdhdddmmdhyyydmmmmmmssssoss\nsssssssssosssyhhhdmNNNNmmddddmNmdhyydmmmmdysssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::://++++/////////++/:/:////+++++///+//////\n///////////////////++++++///////////+++++//:::////\n://::::://////////++/++/:::://///++++++++++////://\n//::::::::::////:://+//////::///////++++///:::--:/\n/:::::::///://///////+osyyyyso////+++++++///::--:/\n:-:://////:://////::/oyhhyysyh+///++/+++/+++//::::\n::///::://--///:::::/sssooo+oyo/:://++++//+++///::\n/////:::/:::///:---:/osssooooso::::/++++//+////++/\n:/://///::-:///::--:/+ossooooo+/::://++++//////+//\n:///:::/::-://://:::/++sssoo+++/::/+++++//:////+//\n/////:://:://///////+//ossoo++++//++/+++/::/:::/+/\n////+/::/:://///:::/+//osoooooshso++++++////::/+++\n//://+/////+++/::/+++++ososso+sddddddhhys+++//+//+\n++/++++/::://+///++/+ssossso++hddddddddddh/++++///\n+///+++/:::/++++++oyhdh+ossoohddddddddddddo/+++//+\n////+/++/::/++//shdddddy+ssyhddddddmddmdddy++++/::\n///+///++///++//hddddmmdsyyyhdddddmmdmmmdddo+///::\n///+/++////+++/+yddmmmmdyyyyhdddddmmdmmmmddho/://:\n++++++//++++++/+ydmmmmmdhhyysyyydmmmmmmmmmddho//+/\n+ooo++///+++++++sdmmmmmmhdhyysssydmmmmmmmmmmmho+++\n+oo+++///+++++++odmmmmmmhdhhhysssydmmmmmmmmmmdo+oo\n+oooo+++++oooo++odmmmmmmdmhdmmddhhmmmmmmmmmmmdoooo\nooooso+oooooooooohmmmmmmdmddmmNNNNmdmmmmmmdddyosss\nossoosoo++oossshdmmmmmmmdmddmmmNNNNmmmmdyyssooooss\nsssosssooosyyyhmmmmNNNNmdmdmmmmmmmmmmmmhooooooooss\nsssssssssosyyyydmmddmNNmddhhdmmmmmmmmmmdssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::::/++++//:://///++//:::////+++++/////////\n////:///////////////+++++++++///////++++++////////\n::/::::::://///////+++++syyyhyso+++++++++++////::/\n///::::::::://///:://+/oyyyyyyyho///+++++//::::-:/\n/:::::::////://://////+sssooo+oys//+++++++///::--:\n:--:://///::://///:::/+osssoooos+//++++++/+++//:::\n:::///:::/:-:///:--:::++sssooo+o+:://+++///++////:\n//////:::/::////---:::/+ossooo++/////++++/++///+++\n://://///:::////::::::/+ossooo+//:///++++//+///+//\n::///:::/::-///://:://+++sssoo+ys+/++++++///////+/\n/////:::/:::////////++//osssoo+hddhhyyyso+///::/++\n://:/+/:////+///:::/+ss/+sso+/sddddddddddd+//::+++\n/+///++////+++/::/oyhddoossooyddddddddddddy++/++//\n/++/++++::://+//ohddddddysssydddddddmddmdddo++++//\n+////+++/:://++/sdddddddyosyhddddddmmddmmdddo+++//\n////++/++/:/++//odddddddh+syhhhhhddmmdmmmmdddho+/:\n////+//++/:/+++/+dddddddhyyhhssssshdddmmmmmmmddho:\n+//++/++////++//+hdmmmmdhyhhdhyssoohdddmmmmmmmmdh/\n+++++++//++++++++ydmmmmmhyhdmmdddyyhddddddddddmmd+\n++ooo+////++++++/odmmdmmdyhdmmmmmmmmmdhdmmmmdddddo\n+ooo+++///+++++++sdmmhmmdhdmmmmmmmmNNmmmhhhhhhysoo\n+ooooo+/++oooooosdmmmdmmdhdmmmmmmmmNmmmdooooo++ooo\noosoosooo+ooossyydmmmmmmddmmmmmmmmmmmmmdooooooooss\noosoooso++ooosysydmddmmmhhmmmmmmmmmmmmmmsoooooooos\nosssosssooosssyyysssdNmdhhmmmmmmmmmmmmmmhoooosssos\nsssssssssssssssssssymNNdhdmmmmmmmmmmmmmmdsssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////::::::/++++/////////++////////++++++//++/////\n////////////////////+++++++/////////+++++/////////\n::/::::://////////++++++osssso+/+++++++++++////://\n///::::::::://///::/+++oyhhhhhys////++++///::::-:/\n/:::::::://////://////osssssssyy+/+++++++///:::-:/\n:--:://///:://////:::/ssssooo+oy//++++++/+++//::::\n:::///:::/:-://::::::++osssooooo////++++//+++++//:\n/////::::/::///:---::/+osssoo+o//////+++//+////++/\n:/:://///:-:////::::://ossooo+///////++++//+///++/\n::///::/::-://////:://+sssooo++////++++++///+//+//\n/////:::/::://////++++osssoo+so++++++++++////::/++\n//////:://://++++oyyo/ossso++hddhysoo++++//+/::+++\n/+///+/////++syhddddo+oss+++yddddddddhs++/++//++/+\n/+/++++/:::/oddddddddyssssoydddddddddddy++++++++//\n+///++++/::/oddddddddyyossyddddddddddddd+//++++//+\n////+//++/:+sdddddmddhyosyhdddddmmmddmddo//++++/::\n///++//++/:+ydddmmmmdhysyydddddddmmdmmmds//++////:\n///+//++///+ydmmmmmmmdyyyhdddddyhhhdmmmdho+++////:\n+++++++//+++hdmmmmmmmmhyyhdmmmdyssssdmmmmds++++/+/\n+oooo+///++ohmmmmmmmmmdhhdmmmmmdyssshmmmmmdy++++++\n+ooo++////+oydmmmdddhhdhhmmmmmmmmdhyhmmmmmmd++++oo\n+oooo++/+++ooddddyyyyydhdmmmmmmmmNmmmmddmmmh+++ooo\noosooo++o+oooshdddhhhdmdmmmmmmmmmNNNNmmdmddyooooos\nossoooso++ooooooydddmmmdmmNNNmmmmNNNNmysssooooooos\nossoosso++oosoooohdmmmmdmNNNNNmmmmmmmmyoooooossoss\nsssssssssossssosymmmmmmdmNNNNNmmmmmmmmhsssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "---:-://:------::::::///::::////::::/+++//////////\n:---:://:-:----::::://////////////::/+++//////////\n:-:-:///:---:--::::/+++++ooosssso++++++/////////:/\n:::-://::::::::::/+ooooosyhhyyhhyyyyssyys++///////\n::-:////////////+++oysyyhddddddddhhhhhdhyyyso++///\n-:-:///:::////+oosshdhdddddddddddhyyhhhyyyhhyso+//\n---///:::////+shhhhyhddddddddddhhhhyhhhhhhhhhhyo//\n--:////://///+syhddddddddddddddddddhddhdddddddhhs/\n--:////////:/+syhddddddddddddmmdddhhhhhhddddddhhs+\n--:://///:::/+osyhddddddddddddddhyyyyyyyhhddddhys+\n--:::::::::::/+osyhhhhdddhhhyysssooo++osyyhdddhys+\n-:::::::::::::+osssyyyyyyyyysssooo+++++osyhhddhys+\n-:::::::::::::+sssssyyyyyyyyysssoo++++++syyhhhhys+\n-:/::-:-------/s+ossyyyyyyyyysssoooo++++osyyhyyso/\n://:----------:++osyyyyyyyyyyssoooooo+++osyyyysso/\n://:-----------:+osyyyyyyyyyyssssoooo+++++oyyyss+:\n///:-----------:+oyhhhhhyyyyyhhhyyyssoo+++osyyso+/\n//:------------:+syyyyhhhyysyyhhhyysssoo++osssoo+s\n//:---------:--/+oyyhhhyyysoosyyhyysooo+++oooossoo\n//:-:-:--:--:-:/+osyyyyyyysooossyyssoooooooooosso/\n//::::::::::::/++oyyyyyyyysooosyyyysssooooooooso+/\n+/:/::/://:////++oyyyhhhhyssssyyyyyssssssoossso+//\n+/////////////++++syhhhhhhyyyyyyyyyssssssssso+++++\n+/////////////+oo+oyhhhhhhhyyyyyyyyysssssssso++o+o\n+/+//////////+ooo++sddddhhyyyyyyhhyyyyssssssoooooo\n+++++++++++++oooo++shdddddhhhhyyyhhyyyyyssssoooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "--:-:///:------::://+oyyhyyhhhhddhhhhhhhhyyoo+++//\n:-:-://:----:-::/++oshdhhhdddddddddddddddddhyhhyso\n::-:///:-:--::/+oyyhhddmmdddddhhhdddddddddddhhyyyy\n-:-:///::::::/ooyhhddddmdddhhdhhddddddddddddddhyss\n::://////////++shdddddddmmddddddddddddmdddmmddddhy\n:::///::://////+yhddddddmmmmdddhhhhdddddddmmmmmddd\n:-:///:::///////oshddddddddddhhyyyyyhhhhddddmmdddd\n--////://////////+syhhhhhhhyysssooosyyhhhddddddddd\n-://///////::/++++ssyyyyyyyyssoooooosyyhhhdddddddh\n-:://///:::::/++++ssyyyyyyyysssoooo+osyhhhdddddddh\n-::::/:::::::///++syyyyyyyyyyssssoooossyhhhhddhhhh\n::::::::::::::///+osyyyyyyyyssssssoooosyhhyhhhhhhh\n:::::::::::::::/+osyyyyyyyyyyssssoooo+ooyyyyyyyyyy\n::::---------:::+oyhhyyyhhhhhhyysssoooo+osyyyyyyss\n://:-----------:/+oyhhyyyyyhhhhyyyysoo++osyyssssso\n//:------------://osyyyyyyyhhhhyysssooo++ooo++ssys\n//:------------//+oysssssyyyyyyyyssooooooo++++osss\n//:------------///ososooosyyyyyyyssoooooooooossooo\n/:------------:///+syyssssyhhhyyysssoooooooossssss\n/:::--:----::-/////syyhhyyyhhhyyysssssooooooooooos\n/:::::::::::::/++//oyhhhhhhhhhhyyssssssssooooooo++\n//:::/::/:////+++///shhhhhhhhhhhyyyssssssssssssooo\n/////////////+++++/++shhhhhhhhhhhyyyyyysssssssssoo\n/////////////+oo++++ooyhhhhhhhyyyyyyyyysssssssssss\n/++/+///////+ooo+++sddddhhhyhhhyyyhhhyyysyyyyssssy\n+++++++++++++ooo+++shdddddhhhhhhhdddhyyyyyyyyyssyh";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "::::::///:::::::::/+yhdmmmmmmmmddddddmmmmmmmmmNNmm\n:----://:-:-:::::::/+yhdmmmmddddhhhhhdddddmmmmmmmm\n:-:-:///:---:::::::/+oyhhhhhyyyysssssyhhhddddmmmmm\n:---://::---:::::::/+osyyyyyyyssssssssyhhhdddmmmmm\n::-://///////////+++ossyyyyyyyyssssoosyyhhdddmmmmm\n-:::///:::///////++++syyyyyyyyyysssoossyhhhddddddd\n---///:::://///////++syyyyyyyyyyyssooosyhhhhhddddd\n--:////:///////////+syyyyyyyyyyyssooooossyhhhhhhhh\n--://///////::/+///+oyhyyyhhhhhyyyssooooosyyyyyyyy\n--://////:::::/++++++syyyyyyhhhhyyysoooooosyyyyyyy\n--::////:::::://+++++osyyyyyyyyyyyyssoooooossssssy\n-:::::::::::::://++++osssyyyyyyyyyssooooooooo++osy\n-:::::::::::::::/+++osoosyyyyyyyysssooooooooooooss\n-::::---------:://++ossyyyyyyyyyyssssoooooooosssso\n://:------------////+osyyyyyyyyyyssssoooooooosssso\n://:------------////:osyyyyyyyyyysssoooooooooooooo\n///:-----------:////:/oyyyyyyyyyyssssoooooooooooo+\n//:------------:///:::/syyyyyyyyyysssssoooooooooo+\n//:---------:--////::::oyyyyyyyyyyysssssoooossooo+\n//:::-------:-:////::::/syyyyyyysyyyyysssssssssooo\n//:::-:::::::::+++///:///+ooyyyyyyyhhysssssssssooo\n+/:/::/::/:/://+++/////////oysyhhhhhhyysssssssssos\n+///://://////++++////+++oyhysyhhhhhhhyyyyysssssyh\n+/////////////+oo+++osyyhhhhsshhhhhhhhhhhhyyysyhhy\n+////////////+oossyydddhhhyssyhddhhhhdddhhhyyhhhys\n++++++++++++osyhddmhhdddddydyyhdddddddddddhhddhyss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "-:-:///:::-:::::::/+shdddhhhhyyyyyyhhddddmmmNNNNNN\n--:///:-:-::::::::/++syyyyyyyssssssyyhhhdddmmmmmmm\n:-:///:-:-:::::::/++ssyyyyyyysssssosyhhddddmmmmmmm\n:-:///:::-:::::::/+osyyyyyyyyysssoosyyhhdddmmmmmmm\n:://////////////+++osyyyyyyyyyyssooosyhhdddddmmmmd\n::///:::////////++osyyyyyyyyyysssooosyhhhhhddddddd\n-///:::://///////+shyyyhhhhhhyyssooooosyhhhhhhhhhh\n:////:///////////++syyyyyhhhhhhyysooooosyyyyyyhhhh\n:////////:::/++//+++syyyyyhhyyyyysoooooosyyyyyyyys\n:://///:::::/+++/++sssyyyyyyyyysssooooooossosysyys\n:::///::::::///+/ossosyyyyyyyyysssoooooooo++osyyso\n:::::::::::::///++syyyyyyyyyyyssssooooooooooosssyo\n::::::::::::::/+++ooyyyyyyyyyyssssooooooooosssooss\n:::---------:::/+++oyyyyyyyyyyssssooooooooyyyssosy\n/:------------/////syyyyyyyyyyssssoooooooooooooosy\n/:-----.------////:/syyyyyyyyyssssssooooooooooooss\n/:-----------:////::+yyyyyyyyyyysssssoooooooooo+o+\n/------------:///:::/syyyyyyssssssssssooosooooo+++\n:---------:--////:::/syyyyyyyyyyyyysssssssssooo+++\n:::-::-:--:-:////:::://+oyyyyyyyyyysssssssssooo+o+\n:::::::::::::+++//////+oyssyhhhyyyyssssssssssooos+\n//://////////++o++oosyyhysyyhhhhhhyyyssssssssssyso\n///////////+osyhhhddhhhhsyhhhhhhhhhhyyyysssssyhyoo\n//////+osyhhdddmmddddhdysydhhhhhhhhhhhyyyssyhhysos\n+++osyhhddmmmmmmmdddddhhhyhddhhhhhhhhhhyyhhhhysooy\nyhhhdddmmmmNNNNNNmhdddddhhhdddddddddddhhhdhysssssh";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":-:-:::///:::-:::::/oydmmmmmmddddddddddmmmmmNNNNNN\n:::::-////::-:::::::+shddhhhhhyyyyyyhhddddmmmmNNNm\n::::-:///:-:-:::::::/+syyyyyyysssssssyhhdddddmmmmm\n::::-:///::::::::::/+ossyyyyyysssssosyhhdddddmmmmm\n::::://///////////+++osyyyyyyyyyssoosyyhhddddmmmmm\n:::::///:::////////+osyyyyyyyyyysoooosyhhhdddddmmd\n--:-:///::://////:/+syyyyyyyyyyssoooossyhhhhhddddd\n----////://////////oyyyyhhhhhhyyssooooosyyyyhhhhhh\n---:////////:::/++/+yyyyyyhhhhhyyysooooosyyyyyyhhh\n---:://///:::::/++++osyyyyyhhyyyyssooooossyyyyyyyy\n---::///:::::::///++sssyyyyyyyyyssoooooooossosysyy\n--:::::::::::::://ossosyyyyyyyyssssoooooo++++ossyy\n--:::::::::::::::/+syyyyyyyyyyyssssooooooooooosssy\n--://:---------:::/o+yyyyyyyyysssssooooooooosssooo\n-:///:-----------:/+oyyyyyyyyyssssooooooooosyyssos\n-://:------------:/+syhhhhhyyysssssoooooooooooooos\n:///:------------///+syyyyyyyyyssssssoooooooooooos\n:///:-----------:////+yyyyyyyyssssssssoooooooooooo\n///:-:--:----:--://///syyyyyyysssssssssooosssooo++\n///:::-::-:::::://+///syyyyyyyyyyyyyssssssssssooo/\n++/:::::::::::::+++////+osyyyyyhhhyyssssssssssooo+\n++//////////////++++///+oyssyhhhhyyysssssssssssooo\n++/////////////+ooooosyyhysyhhhhhhyyyysyyyssssssss\no+/////////++osyhhdddhhhhsyhhhhhhhhhyyyyyyyssssyhs\no+++++++osyhhddmmmmmddddddhhyyhhhhhhhhhyyyysyyhhyo\noo+osyhhdddmmmmNNNNNmhddddddyhddddddddhhyyyyhdhyss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":-:::///:::::+oyhddddddddhddddddddddddddhhyyso++//\n:-:-:///::::+syhddddddddddddmmmddmmmmmmmmdhhyyyyo/\n::::///::::/oyhhdddmmddddddmmmmmmmmmmmmmmmmdysyhyo\n-:-:///:::::/oyhddmmmmdddddddddddmmmmmmmmmmmdyysss\n::://////////+shdddddddhhhyyyhhhddddddmmmmmmmmdhyy\n:::////:://///+syhhyyyyyssssssyyhhhhddddmmmmmmmmdh\n:-:///::://////+syyyyyyyssssoosyyhhddddddmmmmmdddh\n--:///////////+ossyyyyyyssssoosyyhhddddddddmdddddh\n--/////////::/+sssyyyyyyyyssooosyhhhdddddddddddddh\n-:://////:::::+ssyyyyyyyyysooooosyhhhhhdddddddddhy\n-:://::::::::/oyyyyyhhhyyyssooooosyyyyhhhhhhhhhhhy\n:::::::::::::/yyyyyyhhhhhyyssooooooyyyyyyhhhhhhhhy\n::/:::::::::::+yyyyyyhhhhyyyysooooosyyyyyyyyyssyhh\n://:----------:+syyyyyyyyyysssoooo+osssosysyyssohh\n://:---------:/ossyyyyyyyyyssoooooo+++++ossyyosshh\n///:---------/ssosyyyyyyyyysssoooooooo+oosssyoshhh\n//:----------:+yyyyyyyyyyyssssooooooooosssooooyhhy\n//:-----------/osyyyyyyyyyssssoooooooosyyssooyhhy/\n//:------:----/oyyyyyyyyyyyssssooooooosssooosyhy+:\n//::::::::::::/oyhhhhhhhyyyysssssoooooossooosyy+//\n//::::::::::::/+oyhhhhhhhyyyyyssssssssssssoosso///\n+///://///////+++syhhhhhhyyyyyyyyssssssssssoo++//+\n+////////////+oo+oyhhhhhyyyyyyyyyyssssysssssoo+++o\n/////////////+ooo+shhhhhhhyyhhhyyyyyyyyyssssoooooo\n++++++/++++++oooo+odddddhhyhhhhyyyyyyyyyyssssssoys\n++++++++++++oosoooshdddddhhhhhhhyyyyyyyyyyyssyssdh";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "-:-:-:///:-:-::::::::////::://///:/://++//////////\n::-:-:///:::::::::::/++++//////////:/+++//////////\n:::::///:::::::://++osssyyyyssoooooo++++//////:///\n:::-:///:::::/+osssssyhhhhddhhyhhhhyssso+/////:///\n::::///////+oshhhhhhdddddddddhhdddddhyhhysoo++////\n:::://////osyhdddddddhhddddddddddddddddhhhhhys++//\n-:-:///::+yhhhdddddddddddmmddddmmmmmmmddhyyhhhs+//\n---://///+oyhhdddddddddddddddmmmmmmmmmmmdhyyyyys+/\n---///////+oydddddddddddddddddddmmmmmmmmmmdhyyyyo+\n--:://////:/shddddhhhhhyyyyhhhdddddddmmmmmmmmdhyo+\n--:://///:::/syyyyyyyysssssyyhhhhhddddmmmmmdddhhs+\n-:::::::::::+osyyyyyysssssosyhhhddddddddmmmdddhhyo\n-::/::::::::+ssyyyyyyysssoosyhhhdddddddddddddddyss\n-://:------:ossyyyyyyyyysoosyyhhhdddddddddddddhyoo\n-://:-:----:osyyyyyyyyyysooosyhhhhhhdddddddddhhyss\n:///-------/yyyyyhhhhyyssoooossyyhhhhhhhhhhhhhhhyy\n///:::-----:oyyyyhhhhhhyyssooooosyyyhhhhhhhyhhhhyy\n///:--------:syyyyhhhhhhyyssoooosyyyyyyyyyssoyhhhy\n///:------:-:oyyyyhhhyyyyysssoooosssssysyysysyddho\n///:::::::::oyyyyhhhhhyyyysssssooooooosyyyysyhdhy/\n+/:::::::::syyyhhhhhhhhyyyyssssssssssssyyysshddh+/\n+////://///+syhhhhhhhhhyyyyyssssssssyyyyssshddho//\n+///////////+shhhhhhhhhhyyyyyssssssshhyyssyhhhs+++\n+////////////ohhhhhhhhhhhhyyyyssssssyyysssyhhyoo++\n++++++//+//+/+yhdddhhddddhhyyyyyyssyyyyysssyyooooo\no++++++++++++oshhhhhhddddddyhyyyyyyyyyyyysssoooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":-:-:///:------:::::///:::::///::/::/++///////////\n:-:-:///::::::::::::///:://////::::://////////////\n::::///:-::::-:::::////::////:/:::://///:/://:/://\n-:-:///::::::::::://++///////::::::////::::::::::/\n::://////////////++++++++o++++++//////////////////\n:::////////////+oossssyyyhyyysso++oo+/////////////\n:-:///::////++sysssssyhhhhdhhhhhyyyyso+++/////////\n--////////oosyhddhhhhhdddddddhdddddhyyyyso++//////\n--///////osyhhdddddhdhhhddddddddddddhyhhhyso+//++/\n-:///////oyhhddddddddhhdddddddddddddddhhhddhys++++\n-:://///:/oyhdddddddddddmmdddmmmmmmmdddhhhhdhys+++\n::::::::::/shddddddddddddddddmmmmmmmmmmdhyhhhyys++\n:::::::::::+ydddddddhhhhhdddddddmmmmmmmmmdhyyyys+/\n://:-:--:-:/oyyyyyyyyyssyyhhhhdddddmmmmmmmmmdhys+/\n://:-:----/ossyyyyyyysssssyyhhhdddddmmmmmmmddhyso/\n///-------/ossyyyyyyssssosyyhhdddddddmmmmmdddhyso/\n//:::-----/sssyyyyyyyyssosyyhhdddddddmmddddddhyss/\n//:------:osyyyyyyyyyyssosyyhhhdddddddddddddhhsos/\n//:---:--:syyyhhhhhyyysssssyhhhhhddddddddddhhhyyo/\n//::::::::+yyyhhhhhhhyyssssssyhhhhhhhdddhhhhhhhh+/\n/:::::::::/oyyyhhddhhhhyysssssyhhhhhhhhhhhddddhh+/\n///:://///+yyyhhhhhhhhhhyyssssyhhhhhhhhhyyhdddhy++\n/////////oyhhhhhhhhhhhhyyyyssssyyyyhhhhhyhydddho+o\n////////oyyhhhhhhhhhhhhyyyyyyyyssssyyhhhyhhddhsooo\n+++/+//++ohhhhhhhhhhddddhhhyyyyyyyyyhyhhyhddhsooos\n++++++++++shhhhhhhhhhdddddhhhyyyyhhhhyyyhddhooooos";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << ":--::///:----:-:::::////::::///::/::/++///////////\n:-:-:///::::::::::::///:://////::::://////////////\n:::-://::::::-::::://///:////:::::::///::/::/:/::/\n::-:///::::::::::://++///////::::::////::::::::::/\n:::://///////////+++++++++++//////////////////////\n:::///////////////+++++++++++/////////////////////\n:-:///:://///////+ossssssyysso+////+//////////////\n--://///////++++osyyyyyyyyhhhyysssss++////////////\n--/////////+syysyhdddddddhyhhhhhhhhyyso+++/////+//\n-::///////osyyhhddddddddhhhhdhdddhhddhysso+//::/++\n-::///////shdhhhdddddddddhhhddddddddddhyyyyso///++\n:::::::::/oyhdddddddddddddddddddddddddhhhyssyo////\n::/:::::::+shhdddddmmmddddddddddddddddddddysss+///\n::/:-:--:-:+shhdddddddddhhhhhhhhddddmmmddddysso///\n://:------:/osyyhhyyyyysssssssyyhhdddmmmmmmdhs+///\n///:------:ossyyyyyyysssoooooosyyhhhddmmdmdhhs+//:\n///::--:--/osyyyyyyyysssoooooooyyhhddddmdddhys+/::\n//:-------/oyyyyyyyyysssssoooosyyhhdddddddhyso+/::\n//:------/osyyyyyyyyyysssssooosyyhhdddddddhhyo//::\n//:::::::oyhhhhyhhhhyyyssssooosyyhhhdddddhhhys////\n//:::::::/syhhhhhhhhhhhhyyssssssyhhhhhdddddhho////\n+///://///ohhhhhhhhhdhhhhhyssssssyhhhhhhhhddh+///+\n+////////oyhyyyyyhhhddhhhhyysssssyhhhhhhyyyhy+++++\n/////////syyyysssyhhhhhhhyyysssssyyyyhyyyyhsoooo+o\n++++++/++syyyysssyhdddddhhyyyyyysysssyhhhyyooooooo\n+++++++++shhhddhhhhhdddddhhhyyyyyyyyyhyhhyooooooos";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "---:-:///::--:-:::::////::::////:::://+///////////\n:-:-:///::::::::::::////://////::::://////////////\n:::-:///:::-::::://+++++///////:::::////:/::/::/:/\n:::-////::::::/+syyyysssssssoo++//::////::::::::::\n-:::////////++oyyssysyyhhhhdhyyyo++++/////////////\n:::////:///ossyyyyyhhddddddddddhyyysyso+//////////\n:::////:/++yhddddddddddddddddddhyysshyso+/////////\n--:////+ossyhdddddddddddhhhhddhhhhyyyyyyyo+///////\n--:///++syyhddddddddddddddddddddddhhhyyyyy+//://+/\n--:////+syyhddddddddddddddddmmddddhhhhhhhy+::::/++\n-::////+ssyhhddddddddddddddddddhhhhhhhhhhs/::::/++\n-::/::/+syyhhyyyyhhhhhhhhhyyysssooosyhhhys+///////\n:///::/oyhhhyyyyyyyyyyysssoooo+++++osyhyso+///////\n:///:::ohhhyyyyyyyyysssssssooo++++++oyhyso+///////\n:///:::+hhhyyyyyyyyyssssssssoooo+++osyyys+/:::::/:\n///:---/yhyyyyyyyyyysssssssoooooo++osyys+//:::::::\n///::::+syyyyyyhhyyyyyyysssoooooo++ooyyo//::::::::\n///:::oyyyssyyhhhhhhhyyyyyyyyyssooooosy+/:::::::::\n//::::+yyooyyyhhhhhhhyyssyyhhyyyssooosso+////:::::\n//::::/yhssyyyhhhhhhhyyooosyyyyssoooosoo+////::/::\n+/::::/shysyyhhhhhhhhhyoooosssssooooosso++////////\n+///://+yysyhhhhhhhhhhysoosssssssoooooo++++++/////\n+///////++oyhhhhhhhhhhyssssyysssssssoo++++++++++++\n+/////////oyhhhhhhhhhhhhhyyyyysssssooo++++++++o++o\n++++++/+++oyhhhhhhhhhddddhhyyyyyssoo+o++o++ooooooo\n++++++++++oyhhhddddhhdddddhhyyyysssooo++o++ooooooo";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////:://///////++////++++++////////++++//////////\n////:-:/::/::///+++++++++/:::///++++++++++++//////\n//::://:::::::://++///+//::::::////++++///:::::/::\n://://:::::::/::///+///+/:::::////++++++//:::-::/:\n-:///:-::/::/:-:////://+ooo+///:::/++++//++//::://\n---:/:://:-::/:////:/oyhhhhyyo:::://+++//+/////::/\n--://:/::/::::://///+syyyssosy/::::/++++/+///////+\n-::/::://::::--:////ssssooo+oy+/::/++++/:/+//////+\n:////////:--:--:////ossssooooo/++/++/++/://:://///\n:::::://:/:-:::////:+osssso+++//////+++///:://////\n::::::/:////::////:/++osssoo+++//+///+++++///:///:\n::/:://///+/:::///+++/+osoooo+o///++++++//++///+/:\n///++/::://+/::////++//ssoooo+hhhysso+++//+++///+/\n////+/:://:///:/++/++++sssss++ddddddddhyo++/+/:::+\n:/:/++::/://///++/+oyho+osso+yddddddddddh++//+/:/+\n//++//+///////++oshdddy++sssyddddmmddddddo++++////\n++/////+//:::/+shddddmdhsyyydddddmmmmmdddo//+++/::\n++/////+//:::/+sdddmmmmdyyyhdddddmmmmmddds///++/::\n++/////+++///++oddmmmmmdyhhdddddmmmmmmmmdh+++++/::\n+++/+//++/++//+odmmmmmmdhhhddmmmmmmmmmmmddso+++///\noo+++++++/+++/+ohmmmmmmdhhddmmmmmmmmmmmmmmho++o++/\noo+++++o++++++oosdmmmmmdhddmmmmmmmmmmmmmmmdoooo+++\noo+++++oo++++oosymmmmmmdhddmmmmmmmmNNmmmmmdooosooo\nssoosoooooooosyyydmmmmmmdddmmmmmmmmNNmmmmmdooooooo\nssssssosooooosyyyhmNNmmmdmmmmmmmmmNNNNmmmmhsosssss\nsssssssssssssshdhmNNNNNmhdddmmmmmNNNNNmmmmysssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////://///////+++///+++++++///////+++++//////////\n///:-:/::/:::///++++++++/:::////+++++++++++////://\n/:::://::::::://++////+////+///////++++///::::/:::\n://///:::::://:////+///oyyyhyys+/++/++++//::--:/::\n-://::-://://:://///:/osyyyyyyys//++++//++//::-://\n--://:///:-:/::///:::/ssssooo+oy/:/+++//+/////:://\n--:///::/::::::///:::/sssssooooo/://+++/+///+///++\n:::/:://::::--://///:/osssso+o++///++++::///+/+//+\n/////////--:--://////+oosssoo++++++++++::/::/+///+\n::::::/:/:-::::////:///+sssooo++///++++///:://+///\n::::://:////::////:/+//+sssooooyo+//+++++////:+/::\n:::://///++/::////++//+osssooosdddhyyso+//++//++/:\n///+//::///+/://+/++sysssssso+yddddddddhy+++///++/\n//://:::/:://:/++oydddhssosooyddddddddddds+/+/::/+\n///++/://://///shddddddsosyyydddddmmddddds+/+/:://\n//+//////////++sdddmmmdsoyyyddddddmmmmmddy++++////\n++/////+/::::/+odddmmmmhyyyhdddddmmmmmdddh+/++/:::\n++/////+/::::/+oddmmmmmhhyyhdhyhdmmmmmddddy//+////\n++/////+////+++oddmmmmmhhhhddsssydmmmmmmddds+++:::\no+//+/++//++/++ohdmmmmmdhhdddsssshmmmmmmmmddoo+///\no+++++++/+++++oohmmmmmmhdddmmhyysydmmmmmmmmdooo++/\no++++++o+++++oooydmmmmmddddmmmdhhdmddmmmmmdsooo+++\noo++++oo++++osssydmmmmmddmmmNNNmmmmmmmmmmdsoosoooo\nsoosoooooooosyyyydmNmmmddmmmNNNNNNNmmmmhsooooooooo\nsssssosooooosyyhhdmddNNdhhmmNNNNNNmmmmmdsoooosssss\nsssssssssssssssydhssdmmdhhmmmmmmmmmmmmmmysssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////:://///////++////++++//////////++++//////////\n///::::/:::::://+++//++++////++/+++++++++++//:/::/\n//::://:::::::://+////+//oyyyyyyo//++++///:::::/::\n://///:::::://::///+///+oyhhhhyyyo+++++++//::--:/:\n-:://:-::/::/:-:////:::+yssoooooss/++++//++//::://\n---://///:--:/:////::::oysssoooooo//+++//+/////::/\n--://:/::/:::::////:::/osssssoooo/:/++++/+//+////+\n-::/::://::::--://///:/oosssso+++//++++/:/+//+///+\n:////////:--:--://////+/+sssoo+++/+++++/://::/+///\n:::::://:/:-:::////://+++sssooo++///+++///:://+///\n:::::://////:://////++++osssoo+yhso+++++++///:/+/:\n::/://////++/::/++osyhyosssss++hddddhyso//+++/++/:\n////+/::://+/:/oyhddddhssoso++ydhhddddddhs+++///++\n////+/:://:////hdddddddyysssshdysssydddddh+/++:::+\n:///++/:/:////+hdddddddyossyhddyssosmmmddh++/+/:/+\n//++//+/+////+odddmmmmmyoyyyhdddysosdmmddd++++////\n++/////+//:::/odddmmmmmdyyyhdddmdhyyddddddo//++/::\n++/////++/:::/oddmmmmmmdyhhhdmmmmmmmddddddhs+++//:\n++/////+++///+sdmmdddmmdhhhdmmmmmmmmmddmmmmdyo+/::\n+++/++/++/++/ohddysshmmdhhhdmmmmmmmmNmmmmmmmmho+//\noo+++++++++++shhyyyyhmmdhhdmmmmmmmmNNNmmmmmmdso+++\noo+++++o+++++ohhdhhydmmdhddmmmmmmmmNNNNmmmmdsooo++\nooooo++oo++++osyddddmmmddddmmmmmmmmNNNNmhhysoooooo\nssossoooooooooossssdmmmddmmmmmmmmmmmmmmmyooooooooo\nssssssssoooooosssssdmmmdhhdmmmmmmmmmmmmmmsooosssss\nsssssssssssssssssssdmmmhhhhmmmmmmmmmmmmmmhssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "//////://///////++////++++++///////+++++//////////\n////:::/:::::://+++++++++/:::/+/+++++++++++////://\n/:::://:::::::://++///+//+ooooo+///++++///:::::/::\n://///:::::://::///+///+oyhhhhhyo++++++++/:::-::/:\n-:://:-://::/:-:////::/oysssssssy/+++++//++//:-://\n---://///:-::/:////:::/ysssooo+oy///+++/+//////::/\n--://:/::::::::////:::/oosssoooo+://+++//+//+////+\n:://::://:-::--://////+ossssoo++///++++/:////++//+\n/////////:--:--///////++osssoo+++/+++++/://:://///\n::::::/::/:::::///:://++osssoo++////+++//+:://////\n::::://///+/::://+/+oo+osssooooo++///+++//++///+/:\n:////////+++/:/+osyhhhossssso+sdhysoo++///+++//++/\n////+/::///+++hhddddddoysoo+++hdddddhhyo/++/+////+\n:///+/:://:/+ydddddddddysssoshddddhssyhds++//+:::+\n///+++/////+sddddddmmmmsossyhdddmdhsoosdh+++/+/:/+\n+++////++///hddmmmmmmmmssyyyddmmmmmysohdh+//+++/::\n++/////++//oddmmmmmmmmmhyyyhdmmmmmmdyshdh+///++/::\n++/////+++sydmmmmmmdhhhyyyhdmmmmmmmmmdddds//+++/::\n+++/+//++yddddmddmdyyysyhhhdmmmmmmmmmmmmmdoo++o///\noo+++++o+ydddmdddmdhyyhhhhdmmmmmmmmNNNmmmmmdsoo+//\noo+++++oosddmmdddmmmmmmdhhdmmmmmmmmNNNNmmmmmyoo+++\noo+++++oo++osyyyhmmmmmmdhddmmmmmmmmNNNNNmmmhoooooo\nssoosooooooooossymmmmmmdddmmmmmmmmmmmmmmmdyooooooo\nssssssssooooosssymmmmmmdddmmmmmmmmmmmmdssooooossss\nssssssssssssssssymmmmmmddhdmmmmmNNNNmmmmysssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
	cout << "/////://///////+++///+++++/////+///+++++//////////\n///:::/:::::::/++++//+++/::::///++++++++++//::/://\n/::://:::::::://++////+////::://///++++///::::/:::\n:////:::::://::///////oyyyhyso+//++/+++++/::--://:\n-::/::::/:::/::////:/oyyyhyyyyo:://+++//++///:-://\n--://////:-:/::///::+yssooo++so:://+++//+///+//:/+\n--:/::/:/::::-:////:/ssssooooo+:://++++//+/++///++\n:///:::/:--:--://///++ssssoo+o+///+++++::////++//+\n/////////:-::-://////+ossooo++/+//+++++/:/::/+////\n::::://://::/:////://+ossooo++++////+++///:///+/:/\n:::::////++/:://+//+++ossooo++/:/+//+++//+++//++::\n/////////+++///+osyys+ssssoo+hysoo+++++///++//++//\n///+/:::///+syyhddddy+sysso+odddddhyso+//++/+/://+\n///++/::/:/sddddddddhyssso+ohdddddddddy/+++/+/::/+\n///+++////+hddddddmmmdsossshddddddddddd+++++++:///\n+++///+++/oddmmmmmmmmdyossydddddmmddddd++///++//::\n++/////+//sdmmmmmmmmmmyyyyhddddmmmdhhdd+/////+/:::\n++////++++ydmmmmmmmmmmhyyhddddmmmmdsssho++//++/:::\no++++++++shmmmmdhhdmmmdyhhmmmmmmmmhsssho+++++++//:\noo+++++osdddddysyyhmmmmhhdmmmmmmmmhyydmyooo++o+///\no++++++osddmmdhyyydmmmmhddmmmmmmNNmddmmmdsooooo+++\nsoooo+ooohdmmmddddmmmmmhdmmmNNNNNNNNmmmmhoooosoooo\nsssssoooooosyymmmNNNNmmhdmmmmNNNNNNNNNmhooooossoss\nssssssssoooosymmmmNNNNmdmmmmNNNNNNdyhhysoossssssss\nssyysssssssssdmmmNNNNNmhhhmmmmmmmmmyssssssssssssss";
	this_thread::sleep_for(0.1s);
	system("cls");
}

void stoliczkiwrestauracji()
{
	unsigned char prawygorny = 201;
	unsigned char lewygorny = 187;
	unsigned char prawydolny = 200;
	unsigned char lewydolny = 188;
	unsigned char poziome = 205;
	unsigned char pionowe = 186;
	int stolik = 1;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << prawygorny;
			for (int j = 0; j < 20; j++)
			{
				cout << poziome;
			}
			cout << lewygorny << "          ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i == 2)
				{
					cout << pionowe << "         " << stolik << "          " << pionowe << "          ";
					stolik++;
					continue;
				}
				cout << pionowe << "                    " << pionowe << "          ";
			}
			cout << endl;
		}
		for (int i = 0; i < 2; i++)
		{
			cout << prawydolny;
			for (int j = 0; j < 20; j++)
			{
				cout << poziome;
			}
			cout << lewydolny << "          ";
		}
		cout << endl << endl << endl << endl;
	}
}

void wyswietlstolik(int nrstolika)
{
	fstream rest;
	switch (nrstolika)
	{
	case 1:
	{
		rest.open("stolik1.txt", ios::in);
		break;
	}
	case 2:
	{
		rest.open("stolik2.txt", ios::in);
		break;
	}
	case 3:
	{
		rest.open("stolik3.txt", ios::in);
		break;
	}
	case 4:
	{
		rest.open("stolik4.txt", ios::in);
		break;
	}
	default:
		break;
	}
	int nrlinii = 1;
	string linia{};
	while (!rest.eof())
	{
		getline(rest, linia);
		if (nrlinii % 2 == 1)
			cout << linia << endl;
		nrlinii++;
	}
	rest.close();
}

void wyswietlpotrawy()
{
	fstream rest;
	rest.open("potrawy.txt", ios::in);
	string linia{};
	int nrlinii = 1;
	int numerek = 1;
	while (!rest.eof())
	{
		getline(rest, linia);
		switch (nrlinii % 3)
		{
		case 1:
		{
			cout << numerek << ". " << linia << endl;
			numerek++;
			break;
		}
		case 2:
		{
			break;
		}
		case 0:
		{
			cout << linia << "zł" << endl << endl;
			break;
		}
		default:
			break;
		}
		nrlinii++;
	}
	rest.close();
}

void wyswietlwina()
{
	fstream rest;
	rest.open("wina.txt", ios::in);
	string linia{};
	int nrlinii = 1;
	int numerek = 1;
	while (!rest.eof())
	{
		getline(rest, linia);
		switch (nrlinii % 3)
		{
		case 1:
		{
			cout << numerek << ". " << linia << endl;
			numerek++;
			break;
		}
		case 2:
		{
			cout << "Kieliszek: " << linia << "zł" << endl;
			break;
		}
		case 0:
		{
			cout << "Butelka: " << linia << "zł" << endl << endl;
			break;
		}
		default:
			break;
		}
		nrlinii++;
	}
	rest.close();
}

void potrawacenawino(int nrstolika, int nrpotrawy)
{
	fstream rest;
	rest.open("potrawy.txt", ios::in);
	string linia{};
	int ktoralinia = 1;
	while (!rest.eof())
	{
		getline(rest, linia);
		if (ktoralinia == ((nrpotrawy * 3) - 2))
		{
			fstream stolik;
			switch (nrstolika)
			{
			case 1:
			{
				stolik.open("stolik1.txt", ios::out | ios::app);
				break;
			}
			case 2:
			{
				stolik.open("stolik2.txt", ios::out | ios::app);
				break;
			}
			case 3:
			{
				stolik.open("stolik3.txt", ios::out | ios::app);
				break;
			}
			case 4:
			{
				stolik.open("stolik4.txt", ios::out | ios::app);
				break;
			}

			default:
				break;
			}
			stolik << linia << endl;
			getline(rest, linia);
			cout << "Wino, które możesz zaproponować: ";
			cout << linia << endl;
			getline(rest, linia);
			stolik << linia << endl;
			rest.close();
			break;

		}

		ktoralinia++;
	}
}

void winodokoszyka(int nrstolika, int nrwina, int glassbottle)
{
	fstream rest;
	rest.open("wina.txt", ios::in);
	string linia{};
	int ktoralinia = 1;
	while (!rest.eof())
	{
		getline(rest, linia);
		if (ktoralinia == ((nrwina * 3) - 2))
		{
			fstream stolik;
			switch (nrstolika)
			{
			case 1:
			{
				stolik.open("stolik1.txt", ios::out | ios::app);
				break;
			}
			case 2:
			{
				stolik.open("stolik2.txt", ios::out | ios::app);
				break;
			}
			case 3:
			{
				stolik.open("stolik3.txt", ios::out | ios::app);
				break;
			}
			case 4:
			{
				stolik.open("stolik4.txt", ios::out | ios::app);
				break;
			}
			default:
				break;
			}
			stolik << linia << endl;
			getline(rest, linia);
			if (glassbottle == 1)
			{
				stolik << linia << endl;
				getline(rest, linia);
			}
			else
			{
				getline(rest, linia);
				stolik << linia << endl;
			}rest.close();
			break;

		}

		ktoralinia++;
	}
}

void drukowanie(int nrstolika, int platnosc)
{
	fstream stolik;
	switch (nrstolika)
	{
	case 1:
	{
		stolik.open("stolik1.txt", ios::in);
		break;
	}
	case 2:
	{
		stolik.open("stolik2.txt", ios::in);
		break;
	}
	case 3:
	{
		stolik.open("stolik3.txt", ios::in);
		break;
	}
	case 4:
	{
		stolik.open("stolik4.txt", ios::in);
		break;
	}
	default:
		break;
	}
	int suma{};
	for (int i{}; !stolik.eof(); i++)
	{
		string linia{};
		getline(stolik, linia);
		if (i % 2 == 0)
		{
			cout << linia;
		}
		else
		{
			cout << " " << linia << "zł" << endl;
			suma += atoi(linia.c_str());
		}
	}
	string rodzaj{};
	if (platnosc == 1)
		rodzaj = "gotówką";
	else
		rodzaj = "kartą";
	cout << "Suma: " << suma << "zł" << endl << "Wybrano płatność " << rodzaj;
	char czekanie{};
	stolik.close();
	fstream stolik1{};
	switch (nrstolika)
	{
	case 1:
	{
		stolik1.open("stolik1.txt", ios::out);
		break;
	}
	case 2:
	{
		stolik1.open("stolik2.txt", ios::out);
		break;
	}
	case 3:
	{
		stolik1.open("stolik3.txt", ios::out);
		break;
	}
	case 4:
	{
		stolik1.open("stolik4.txt", ios::out);
		break;
	}
	}
	stolik1.close();
}
