/*
* John Durham
* CIS 2207
* 02/16/23
You are asked to complete Programming Problem 9 on page 352 of your textbook. This program is meant to apply what you have learned 
in this topic.
Write a program to display the running time of the sorts described in this chapter.  Test the sorts on arrays of various sizes.  
Arrays of the same size should contain identical entries.  Use the clock from <ctime> to time each sort.  See the beginning of the 
programming problems in Chapter 10 for an example of how-to time code.

The Selection Sort (Listing 11-1 on pp. 327-328)
The Bubble Sort (Listing 11-2 on p. 330)
The Insertion Sort (Listing 11-3 on pp. 332-333)
The Merge Sort (Listing 11-4 on pp. 335-337)
The Quick Sort (Listing 11-5 on p. 344)
The Radix Sort (See pseudocode on p. 348)
*/

#include <iostream>
#include <ctime>
#include <string>
//#include "Sort.h"  build fails in seperate files for some reason

//consts
const int MIN_ARR_SIZE = 20;
const int MAX_ARR_SIZE = 200;

//protos
int mainMenu();

int subMenu();

void printTestsPre();

void printTestsPost(double results);

template<class itemType>
void printArr(itemType arr[], int size);

template<class itemType>
void printSortedArr(itemType arr[]);

template<class itemType>
void tbubbleSort(itemType arr[], int arrSize);

template<class itemType>
void tswap(itemType a, itemType b);

template<class itemType>
int tfindLargestIndex(const itemType arr[], int arrSize);

template<class itemType>
void tselectionSort(itemType arr[], int arrSize);

template<class itemType>
void tinsertionSort(itemType arr[], int arrSize);

/*template<class itemType>
void tmerge(itemType arr[], int first, int mid, int last, const int size);

template<class itemType>														//array at line 690 itemType unassignable???????
void tmergeSort(itemType arr[], int first, int last, const int size2);*/

template<class itemType>
void tsortFirstMiddleLast(itemType arr[], int first, int mid, int last);

template<class itemType>
int tpartition(itemType arr[], int first, int last);

template<class itemType>
void tquickSort(itemType arr, int first, int last);

template<class itemType>
auto tgetMaxValue(itemType arr[], int size);

//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
/*
template<class itemType>
void tCountingSort(itemType arr[], int size, int div);

//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
void tradixSort(itemType arr[], int size);*/


int main() {
	//vars
	int choice;
	int subChoice;
	double overallTime;
	clock_t start, finish;

	//test arrays
	int testInt1[20] = {
		12, 56, 23, 4, 3, 6, 7, 23, 67, 78, 89, 123, 321, 43, 54, 87, 43, 65, 66, 20
	};

	int testInt2[200] = {
		120, 451, 863, 712, 714, 14, 99, 286, 932, 459, 626, 885, 49, 637, 246, 522, 716, 359, 260, 705, 
		110, 46, 719, 958, 870, 536, 951, 460, 708, 846, 514, 356, 964, 730, 73, 519, 895, 503, 570, 905, 
		657, 22, 575, 544, 247, 127, 490, 590, 606, 240, 19, 865, 138, 995, 159, 583, 594, 128, 20, 478, 
		106, 54, 938, 201, 89, 101, 16, 902, 322, 119, 17, 516, 176, 775, 438, 894, 732, 854, 558, 664, 197, 
		397, 812, 70, 998, 164, 655, 823, 157, 940, 578, 102, 983, 61, 709, 731, 808, 681, 250, 777, 195, 
		275, 826, 656, 288, 252, 53, 943, 974, 183, 111, 28, 422, 261, 396, 341, 538, 351, 990, 788, 699, 
		254, 178, 471, 429, 199, 491, 722, 407, 797, 766, 989, 383, 506, 305, 402, 691, 232, 385, 956, 56, 
		287, 226, 787, 620, 899, 646, 772, 533, 306, 665, 371, 395, 643, 198, 470, 404, 30, 841, 177, 507, 
		616, 547, 150, 988, 844, 550, 869, 78, 441, 132, 946, 746, 370, 494, 749, 258, 925, 545, 748, 737, 
		86, 121, 874, 126, 37, 487, 68, 835, 618, 765, 204, 969, 510, 420, 314, 301, 60, 701, 688
	};

	char testChar1[MIN_ARR_SIZE] = {
		'G', 't', 'A', 'n', 'C', 'X', 'S', 'a', 'l', 'U', 'q', 'j', 'x', 'D', 'r', 'H', 'P', 'f', 's', 'w'
	};

	char testChar2[MAX_ARR_SIZE] = {
		'W', 'R', 'O', 'o', 'P', 'o', 'p', 'G', 'X', 'a', 'q', 'V', 'F', 'f', 'u', 'z', 'O', 'e', 'T', 'h', 'E', 'h', 'b', 'q',
		'Y', 'M', 'o', 'u', 'e', 'f', 'a', 'Z', 'm', 'b', 'Q', 'A', 'd', 'P', 'k', 'N', 'K', 'r', 'A', 'e', 'q', 'K', 'k', 'g',
		'Q', 't', 'e', 'g', 'v', 'D', 'Q', 'w', 'N', 'c', 'B', 'x', 'U', 'S', 'E', 'x', 'S', 'h', 'R', 'E', 'C', 'K', 'F', 'e',
		'b', 'U', 'O', 'n', 'r', 'M', 'n', 'b', 'O', 'q', 'a', 'W', 'c', 'K', 'a', 'r', 'u', 'J', 's', 'A', 'b', 'h', 'r', 's',
		'R', 'o', 'e', 'a', 'o', 'S', 'u', 'm', 's', 'S', 'G', 'C', 's', 't', 'z', 'y', 's', 'J', 'v', 'U', 'R', 'A', 'G', 'J',
		'R', 'r', 'V', 'v', 'e', 'a', 'A', 'f', 'u', 'W', 'Q', 'v', 'H', 'q', 'k', 'k', 't', 'c', 'O', 'F', 'X', 'R', 'e', 'T',
		'p', 'C', 'T', 'x', 'X', 'g', 'O', 'j', 'M', 'n', 'G', 'Z', 'Q', 'p', 'K', 'u', 'p', 'R', 'm', 'Z', 'b', 'p', 'p', 'F',
		'b', 'P', 'H', 'h', 'A', 'w', 'v', 'E', 'y', 'H', 'U', 'R', 'U', 'Y', 'J', 'C', 'v', 'Z', 'X', 'p', 'v', 'H', 'B', 'B',
		'B', 'z', 'W', 'F', 'M', 'v', 'D', 'K'
	};

	std::string testString1[MIN_ARR_SIZE] = {
		"FyNvlOJzpuRUsWteLByp",
		"cIlHOcNGpRSDolMlXHwr",
		"ASJhodWZOPzqrqScqQQX",
		"LdQlxMqDDUDxPLEbzKvu",
		"AiKcJAkUpqZAiBSzlwhk",
		"GoiXADoTGJWWtUQslAx",
		"czMvTTfehovPynCqwIfS",
		"xFBZCOKcloVDHupSXqcT",
		"cckrbsOYkIxjqCWGwcnQ",
		"ENgYFaKwxFxxoTBVtwDJ",
		"bTCsswFGnLRHnefMSueb",
		"JIzIwdgXQtaLCAZDvzNd",
		"xxouVAfhlUCHDXBmdGkz",
		"MkybsjHkGrJbcdeBakyT",
		"wxnvUkDJjyDzGudtVoHI",
		"xKPgCxWDgTAfgLUipaJG",
		"GYesVdOVKBqxtxNycXjA",
		"wfEWnQIAJfHKgsNVGLTR",
		"eCuFFWNAcaqLIurhTHIh",
		"vRURJvvZNXHqbkGGKMpk"
	};

	std::string testString2[MAX_ARR_SIZE] = {
		"zWXEEHSEeGAnFDGOqDjA","zEDhKrocYEEGpHWTVwvD","rSdwTAgTYywnRBzAadQs","KYsQzKQXJcYkGGogoseV","KRHthaZSWNHfwFHrwvZR",
		"ZfPSqadREUTpQbvrpzju","ZgKEVUxDyWzpqhKFmSUc","OGPgwasqQrZhYsPFdxYz","CbUjtbfCvUwYFpgeXkbp","MSpqTudOhqmJkNDtMefU",
		"hASUtDtcNESqBgnxyqTA","YQXSqqGenTeSghucvocd","asCkTmjDZpFmVccbDJkV","JOoGykQPrkgNknvqTbye","ywEtbkcuoaOKCwSjfFZe",
		"fRKPoXfwErdokeRGnTFD","bMFxuwZkvtyDwysKpmRQ","EmFGVdyTYmCCcWXoFQys","JyCeHzVRtBbWUVWbVRCN","PQuNuYAhjOXhvsmvxuzT",
		"HMkAmvSWEGHAWphVgXVc","MGVcybujkzsDuwMqAdTy","WvTMevEMAdQfoePaEAja","ndvrfOaPcSufCcepTrtm","AZDErPsrNxyFhhyZBDaP",
		"kYxJgjDJsKjdmvxvYwvZ","bmfTzpVyCWaxZpcsFyPd","yWVojdfhkBOPJNoKTVam","yYAWeVdcoNrnZCnkGgWV","xKopuKkbjgSTjnnEgNHs",
		"eamNdjXbPthpoSYKRCTq","ZPbZNnyTJFbbKqYXaftS","wDcHfqBJSOUBwtUzkMAE","aBoFBjpzsAoTdTZgpvfd","rJmrqpEEBwZnnFjCtuGH",
		"kpVCjRGokeKVvjCaOjwt","DYuWkAJarDfEsNmWqATS","fRqVRMbfXBsPOUPboGZr","ogGueKYfJFcVyjjohdVY","AkRcoebdGMKTWwPcRxfa",
		"fNusoobgCWtWeBpavCAm","pVVDRPOaZJAwwxXGwNma","zSyJSoHwpOBfoWacbUYc","WrtJYgPzMmAmXAnjxSve","cxpMhwJvmCgbPWHmVJfo",
		"oBmcCzqBctfhuoJXNKEM","dufTxjFryproFvujFBnB","royBPApsysctsDaFfMrf","oAbNbEQFecQHtWXmaUjU","TTDDjoDxBrRcrNmeMCOo",
		"hTkfOxxezZubgHFjntZH","TDadPhXGwmpOgACgqVJF","rUarHUyFqqbeStGGUpoz","mAXAHQUBjQwEmNFMeNjQ","fqmVEMPzZdnxhdSDPnQs",
		"JBkYbhmeJyWPMTWCxSAV","DNTPScejMQoWNaVMDCyN","CowQpxjZzzezJPSaokBZ","wkCZHmdAqkTyBaoZPeDD","vnXrANcvJvemnbBWdhwM",
		"cTWgnGesZGqDXxfTVTnu","WJgaFmJbOJazfyRBrDzR","ecyrUkbzghphtpJdaGoa","ygJyrfJdpOJjqXoKBDTW","maWNmTYWPztNFDmCmUfZ",
		"gAhgpajgDyHkTtCDNNyS","PkouAZpsOTKjcSrKmGNc","hOPTgxkHfNwQUfhZsDrp","prYhxcwqBUdSQBVJtTkN","yaxSyWJBtoqfCHCzjphF",
		"BDWOaDexQTJTgbfSCaGy","PVHjohpdvOzXTXChKngb","tFmNWUxtYJyuNVBzqKfo","nhbddTvmdynWcgZkTnPF","ODWbOeZuNdygZbrJBhCN",
		"mWzzujnfADUBtEcrYHzB","DvVxVMOSqotpaMpKZdOY","JDnutuortXjzmEFAefSr","bbyXZBhXmtzMHyncuwOJ","oeegcHaqzpwmfmtZkcaJ",
		"JpWHqWtrOTxryTYYnJOh","awdDMsUXkQekcUwUUvKh","AYfhDhSKHgvoMRXQehvq","sOmZhEVaxwapwHsuvnUr","hdNYpCagkZxONcCdRbMn",
		"jqZwFnCCcsHMWafekzKH","ZTRJusXsTAcvdcCVaqWc","ESyAuSzQDVCQWjhZqtxO","aObBruzbEkfgfdfYXSra","FWGEJXCBVyrUPuAmUjuk",
		"NutYbzcECBpBSXcqwoZS","YDebeVSupNtumOwxgVWV","CNfQcvZuTjkVMUckQHds","AxsraBhxzMMzobkWzHrm","HuePQyFdPDjqoHbSmuJS",
		"AZDTFkZmPYONmHtgfxCH","FwXrynBUpggtzYnWxngW","VhojEysVmARTBpwgTYtG","XUWwYfUsMrvuhXgUMXvQ","GbybSPaEouyxZnVQAzyT",
		"HTyDZdpJDAYJMgVTpyVT","ZnBEXuSzNtcjzbjEqvjT","RTtadCNgsNkTMYbHrbBz","WtxExbevjNNPwZCtYynr","WEEWRBvtMjOZFxMeAsuu",
		"ecujBNyZUngQUDTBJqan","EzxVuKtTYHOJccHfZkgu","xcXoDbUvXepMghzrDGBm","CVcNkVAKsXDwvgOTfrJF","pkhdddXEZPczQprcrbhT",
		"phCBorTBeHqNRNkOCVme","dzuqgqOjQasfuCzsSXDA","OqNSvrCRTCUoyGmwSyPM","RfxUNbODHZYYjgGNUspw","eWZgdDNnnoHCcQubrhRy",
		"tWMphCbnPTZaBPeQAdOQ","OrjonFqpTRwaEafVUypG","wFrpsqFAKCjYgeAqHJTx","khJJBOOkDXduDHfQwYTh","nsHbuEgghDKQCpUPFuSp",
		"YrwKMsQttyBkFujAGfgT","BGaWcOMuZcWVzFCJDtAg","teGbpnTpQwkxGwCXJyoB","MVDxUQJnQRTpNjxJzNSj","eHremNYFVCHMnOMkmAkM",
		"oWmsmNoYbvuHGTKUrkjT","tzyaUGnbcwkgJjuhJgYz","WkbPMQoypFxgkSCeVUvN","CtxTBFWfUttYjvsFrvTk","ZrmxAOutmjBxdUZTqJgk",
		"dcFbyYFOPVWCAhhYEWEd","GdswRTyJwjoTqzaEdBuX","ztnTxHeWtQOQfZdTEjsW","ynjvSJjkqssrAajxjPkq","sEDyQpfVmaYwZNUkwetn",
		"numZsJTHZOynKVsUEJMK","kHXpkDCGSBXCuzXGKkBX","RYFZxpfFhKwDQVNOsSZw","WGToracdTxusKfusbTwj","xBDeVXkUcweOahfnOmaH",
		"ZZoosdEFgOuxPeTQFnHr","WqwjxJUMVTCBnDmzYGQV","VBojcAakSKABOkHxsqen","PtgTKWFHoVpWamYRDxqU","WaOZNDpqcMWJfSmQqpdJ",
		"yYCCMNJOOHcWpKtztSOO","tqaZxuWguAGDmRTfhekx","ENCRZEQKKKDOGJKNJdUr","fKNgeZoyczVrNJEKPObM","pnqUUQhSxyFmHZFrpkhN",
		"WRCeseNAkzhAOwRvfMqP","KHgakpjdwOOanEZkJpDV","AkWbsTpjntHGROaZcKJe","hphvvkfQQHxUqoWjXpHd","rujeyKqZkjrHwNPyXGns",
		"xdxjAAWuPCkDMfCvxHmv","tKpHBRVyrrZNAQwEnqJc","ZhJcAXFOYFvJuKqQeFdh","UoUaVykMZjSHEsAKYGKN","htTKbHRhJJGsBpZvdkFo",
		"PhvyOhxccmyaEocwBqhF","WVrvOzkfKFoyvmpmBWaj","vWYQctTWwOVtOZhqVXAG","CKUbjjrMDksQPzUGvpxr","SaOXHWUOSmuJzHoxhxWp",
		"rShXHbuTYmbShVOEXktV","eMyqkkoGJdUtbFrkfKvP","UvMfUUYuGFZqqFvczgyw","pcYTsGPOYQYuvxSJebCn","yfAyvzDDeahTdoKeDCsZ",
		"ysogTNzaGQneHHoxoeKW","NnPSPuhTYphqEYyYJTgs","knTJcEUAraxCXDQdtmSr","TTWUacGsqCQabyxHoZFg","CDwhsrapvRZZGHJXDNnD",
		"CovVrohfOkFeQjEOmZBF","JZugsQfSmowKXFpamXPc","FbCugWrJeokrUnPtcABr","pxdMyAcMxzyPjeqaEFog","fhHhFMwtznurnBjpdtXE",
		"hJnnptCSxnFKKXvCerDb","mfyeEbuvzaUBaCzeREZg","sbUNKEczjzoUaSmaeZwh","vthqVgCWwYduAaTTgHdm","WHaGssxvBMeYYGkWZtua",
		"UVwJhOeAyQEBVRvjBFnh","jphyMTzNtxThuJVBPtAn","JREyBecDsjUeNsydhxsT","CCjZsZxQpeGNvxdTQDBA","FRGOkoOnOysmhfYosFAH",
		"qtoyyQGOtZGwexCFDunR","gVSvFJvNQGjpdBXdzhvC","qbyjaUQxBAPRYqONbUmw","DQuPJYHgqVkraUSRZfsK","DPRcvovjgsEFKCKYQNGd",
		"fMcsJjnWcGznUfjhABUa","bVdZedqAaPZfWAEcxUVA","bqmhPPXRUKrgXQtAnbUw","MSTpdpPHrgnEaJJjnhKR","RKrDKqxpzqpnSJAHgeXv"
	};


	//fnally
	do {
		choice = mainMenu();
		system("CLS");
		if (choice == 7)
			break;
		subChoice = subMenu();
		system("CLS");

		//main switch
		switch (choice)
		{
		case 1://selection
			switch (subChoice)
			{
			case 1://small int
				printArr(testInt1, 20);
				printTestsPre();
				start = clock();
				tselectionSort(testInt1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printArr(testInt1, 200);
				printTestsPre();
				start = clock();
				tselectionSort(testInt2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				tselectionSort(testChar1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				tselectionSort(testChar2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				tselectionSort(testString1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				tselectionSort(testString2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
			break;
		case 2://bubble
			switch (subChoice)
			{
			case 1://small int
				printTestsPre();
				start = clock();
				tbubbleSort(testInt1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printTestsPre();
				start = clock();
				tbubbleSort(testInt2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				tbubbleSort(testChar1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				tbubbleSort(testChar2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				tbubbleSort(testString1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				tbubbleSort(testString2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
			break;
		case 3://insertion
			switch (subChoice)
			{
			case 1://small int
				printTestsPre();
				start = clock();
				tinsertionSort(testInt1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printTestsPre();
				start = clock();
				tinsertionSort(testInt2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				tinsertionSort(testChar1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				tinsertionSort(testChar2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				tinsertionSort(testString1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				tinsertionSort(testString2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
			break;
		case 4://merge
			switch (subChoice)
			{
			case 1://small int
				printTestsPre();
				start = clock();
				//tmergeSort(testInt1, MIN_ARR_SIZE, MAX_ARR_SIZE, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printTestsPre();
				start = clock();
				//tmergeSort(testInt2, MAX_ARR_SIZE, MAX_ARR_SIZE, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				//tmergeSort(testChar1, MIN_ARR_SIZE, MAX_ARR_SIZE, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				//tmergeSort(testChar2, MAX_ARR_SIZE, MAX_ARR_SIZE, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				//tmergeSort(testString1, MIN_ARR_SIZE, MAX_ARR_SIZE, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				//tmergeSort(testString2, MAX_ARR_SIZE, MAX_ARR_SIZE, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
		case 5://quick
			switch (subChoice)
			{
			case 1://small int
				printTestsPre();
				start = clock();
				tselectionSort(testInt1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printTestsPre();
				start = clock();
				tselectionSort(testInt2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				tselectionSort(testChar1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				tselectionSort(testChar2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				tselectionSort(testString1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				tselectionSort(testString2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
			break;
		case 6://radix
			switch (subChoice)
			{
			case 1://small int
				printTestsPre();
				start = clock();
				//tradixSort(testInt1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 2://large int
				printTestsPre();
				start = clock();
				//tradixSort(testInt2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 3://small char
				printTestsPre();
				start = clock();
				//tradixSort(testChar1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 4://large char
				printTestsPre();
				start = clock();
				//tradixSort(testChar2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 5://small string
				printTestsPre();
				start = clock();
				//tradixSort(testString1, MIN_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			case 6://large string
				printTestsPre();
				start = clock();
				//tradixSort(testString2, MAX_ARR_SIZE);
				finish = clock();
				overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
				printTestsPost(overallTime);
				system("PAUSE");
				system("CLS");
				break;
			}
			break;
		}

	} while (choice != 7);


	std::cout << "Good-Bye!" << std::endl;


	return 0;
}



int mainMenu()
{
	int selection;
	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "|                              Searching and Sorting Algorithms Test Main Menu:                           |" << std::endl;
	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "|                                               1. Selection Sort                                         |" << std::endl;
	std::cout << "|                                               2. Bubble Sort                                            |" << std::endl;
	std::cout << "|                                               3. Insertion Sort                                         |" << std::endl;
	std::cout << "|                                               4. Merge Sort - UNAVAILABLE! See Source code notes        |" << std::endl;
	std::cout << "|                                               5. Quick Sort                                             |" << std::endl;
	std::cout << "|                                               6. Radix Sort - UNAVAILABLE! See Source code notes        |" << std::endl;
	std::cout << "|                                               7. Quit                                                   |" << std::endl;
	std::cout << "|                                                                                                         |" << std::endl;
	std::cout << "|                                          Please enter your selection:                                   |" << std::endl;
	std::cout << "===========================================================================================================" << std::endl;
	std::cin >> selection;  //TODO - needs validation
	return selection;
}


int subMenu()
{
	int selection;
	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "|                              Searching and Sorting Algorithms Test Sub Menu:                            |" << std::endl;
	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "|                                               1. Small Integer Array                                    |" << std::endl;
	std::cout << "|                                               2. Large Integer Array                                    |" << std::endl;
	std::cout << "|                                               3. Small Char Array                                       |" << std::endl;
	std::cout << "|                                               4. Large Char Array                                       |" << std::endl;
	std::cout << "|                                               5. Small String Array                                     |" << std::endl;
	std::cout << "|                                               6. Large String Array                                     |" << std::endl;
	std::cout << "|                                                                                                         |" << std::endl;
	std::cout << "|                                                                                                         |" << std::endl;
	std::cout << "|                                          Please enter your selection:                                   |" << std::endl;
	std::cout << "===========================================================================================================" << std::endl;
	std::cin >> selection;  //TODO - needs validation
	return selection;
}


void printTestsPre()
{
	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "|                              Searching and Sorting Algorithms Test Results:                             |" << std::endl;
	std::cout << "===========================================================================================================" << std::endl;
}


void printTestsPost(double results)
{
	std::cout << "###########################################################################################################" << std::endl;
	std::cout << "TIME RESULTS >> " << results << " seconds" << std::endl;
 	std::cout << "===========================================================================================================" << std::endl;
	std::cout << "" << std::endl;
}


template<class itemType>
void printArr(itemType arr[], int size)
{
	std::cout << "Array to sort: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}


template<class itemType>
void printSortedArr(itemType arr[])
{
	std::cout << arr << std::endl;
}


template<class ItemType>
void tbubbleSort(ItemType arr[], int arrSize)
{
	std::cout << "Starting \"Bubble Sort\"........" << std::endl;
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < arrSize))
	{
		sorted = true;
		for (int index = 0; index < arrSize - pass; index++)
		{
			int nextIndex = index + 1;
			if (arr[index] > arr[nextIndex])
			{
				//std::cout << "\"Swapping\"........" << std::endl;
				tswap(arr[index], arr[nextIndex]);
				sorted = false;
			}
		}
		pass++;
	}
	std::cout << "Finishing \"Bubble Sort\"........" << std::endl;
}


template<class itemType>
void tswap(itemType a, itemType b)
{
	itemType temp = a;
	a = b;
	b = temp;
}


template<class itemType>
int tfindLargestIndex(const itemType arr[], int arrSize)
{
	//std::cout << "Finding \"Largest Index\"........" << std::endl;
	int indexSoFar = 0;
	for (int currentIndex = 1; currentIndex < arrSize; currentIndex++)
	{
		if (arr[currentIndex] > arr[indexSoFar])
		{
			indexSoFar = currentIndex;
		}
	}
	return indexSoFar;
}


template<class itemType>
void tselectionSort(itemType arr[], int arrSize)
{
	//int tempArr[arrSize] = {};
	std::cout << "Starting \"Selection Sort\"........" << std::endl;
	for (int last = arrSize - 1; last >= 1; last--)
	{
		int largest = tfindLargestIndex(arr, last + 1);
		tswap(arr[largest], arr[last]);
	}
	std::cout << "Finishing \"Selection Sort\"........" << std::endl;

}


template<class itemType>
void tinsertionSort(itemType arr[], int arrSize)
{
	std::cout << "Starting \"Insertion Sort\"........" << std::endl;
	for (int unsorted = 1; unsorted < arrSize; unsorted++)
	{
		itemType nextItem = arr[unsorted];
		int location = unsorted;
		while ((location > 0) && (arr[location - 1] > nextItem))
		{
			arr[location] = arr[location - 1];
			location--;
		}
		arr[location] = nextItem;
	}
	std::cout << "Finishing \"Insertion Sort\"........" << std::endl;
}


/*template<class itemType>
void tmerge(itemType arr[], int first, int mid, int last, const int size)
{
	//std::cout << "Starting \"Merge\"........" << std::endl;
	//int size = arr.size();
	//itemType *tempArr = new itemType[last]();
	//itemType tempArr[size];
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			tempArr[index] = arr[first1];
			first1++;
		}
		else
		{
			tempArr[index] = arr[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		tempArr[index] = arr[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArr[index] = arr[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		arr[index] = tempArr[index];
	}
	//std::cout << "Finishing \"Merge\"........" << std::endl;
	//delete tempArr;
}


template<class itemType>
void tmergeSort(itemType arr[], int first, int last, const int size2)
{
	std::cout << "Starting \"Merge Sort\"........" << std::endl;
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		tmergeSort(arr, first, mid, size2);
		tmergeSort(arr, first, mid + 1, size2);
		tmerge(arr, first, mid, last, size2);
	}
	std::cout << "Finishing \"Merge Sort\"........" << std::endl;
}*/


template<class itemType>
void tsortFirstMiddleLast(itemType arr[], int first, int mid, int last)
{
	std::cout << "Starting \"SortFML\"........" << std::endl;
	if (arr[first] > arr[mid])
		swap(arr[first], arr[mid]);

	if (arr[mid] < arr[last])
		swap(arr[mid], arr[last]);

	if (arr[first] > arr[mid])
		swap(arr[first], arr[mid]);

	std::cout << "Finishing \"SortFML\"........" << std::endl;
}


template<class itemType>
int tpartition(itemType arr[], int first, int last)
{
	std::cout << "Starting \"Partitioning\"........" << std::endl;
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(arr, first, mid, last);
	swap(arr[mid], arr[last - 1]);
	int pivotIndex = last - 1;
	int pivot = arr[pivotIndex];

	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool done = false;
	while (!done)
	{
		while (arr[indexFromLeft] < pivot)
			indexFromLeft = indexFromLeft + 1;

		while (arr[indexFromRight] > pivot)
			indexFromRight = indexFromRight - 1;

		if (indexFromLeft < indexFromRight)
		{
			swap(arr[indexFromLeft], arr[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else
		{
			done = true;
		}
	}

	swap(arr[pivotIndex], arr[indexFromLeft]);
	pivotIndex = indexFromLeft;

	std::cout << "Finishing \"Partitioning\"........" << std::endl;
	return pivotIndex;

}


template<class itemType>
void tquickSort(itemType arr, int first, int last)
{
	std::cout << "Starting \"Quick Sort\"........" << std::endl;
	const int MIN_SIZE = arr.size();//TODO - this cannot EVEN be correct
	if ((last - first + 1) < MIN_SIZE)
	{
		insertionSort(arr, first, last);
	}
	else
	{
		int pivotIndex = partition(arr, first, last);
		quickSort(arr, first, pivotIndex - 10);
		quickSort(arr, pivotIndex + 1, last);
	}
	std::cout << "Finishing \"Quick Sort\"........" << std::endl;
}


//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
auto tgetMaxValue(itemType arr[], int size)
{
	auto max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}


/*
//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
void tCountingSort(itemType arr[], int size, int div)
{
	std::cout << "Starting \"Counting Sort\"........" << std::endl;
	itemType output[size];								//C3863 - itemType[size] unassignable
	itemType count[10] = { 0 };

	for (int i = 0; i < size; i++)
		count[(arr[i] / div) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / div) % 10] - 1] = arr[i];
		count[(arr[i] / div) % 10]--;
	}

	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}


//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
void tradixSort(itemType arr[], int size)
{
	std::cout << "Starting \"Radix Sort\"........" << std::endl;
	auto val = tgetMaxValue(arr, size);
	for (auto div = 1; div > 0; div *= 10)
		tCountingSort(arr, size, div);
}
*/


