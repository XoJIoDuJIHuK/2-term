#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int N=2,K=4;
	const int n = 5;
	
	string mass2[n];
	ifstream fs("strings.txt");

	if (!fs) { 
		return 1; 
	} 
	for (int i=0; i < 5; ++i) {
		if(i==4){
			fs >> mass2[i];
			cout << mass2[i];

		}
		else {
			fs >> mass2[i];
			cout << mass2[i];
			cout << endl;
		}
	}
	fs.close();
	 ofstream fs2("file2.txt", SEEK_END);
	if (!fs2) {
		return 1;
		cout << "не удалось открыть файл";
	}
	for (N=N-1; N <= K-1; ++N)
	{
		if (N == K - 1) {
			fs2 << mass2[N];

		}
		else {
			fs2 << mass2[N];
			fs2 << endl;
		}
	}
	fs2.close();
	
	char sogl[] = "БбВвГгДдЖжЗзЙйКкЛлМмНнПпРрСсТтФфХхЧчЦцШшЩщ";
	ifstream in("file2.txt", ios::in | ios::binary);
	char ch;
	int vcount = 0;
	while (in.get(ch)) if (strchr(sogl, ch)) vcount++;
	cout<<"количество согласных" << vcount << endl;
	system("Pause");
	

	return 0;
}