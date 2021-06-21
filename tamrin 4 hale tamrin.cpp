//
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;
struct ipstruct
{
	int count;
	string addr;
};


class ids
{
protected:
	ipstruct ip[20000];

public:
	ids() {//for(int i=0 ;i<20000;i++ )
	
	//	ip[i] = a;
	
	};
	void add_ip_to_data(string);
	int khondan(string);
	void moratabk();
	void show();
	void sercheip(string);
private:

};
void ids::sercheip(string ipp)
{
	for (int i = 0; i < 20000; i++)
	{
		if (ip[i].addr != "") 
		{
			if (ip[i].addr.find(ipp) != std::string::npos)
			{
				cout << ip[i].addr << " - " << ip[i].count <<endl;
				
			}
		}
		else
		{
			cout << "not found";
			break;
		}
	}
}
void ids::add_ip_to_data(string a)
{

	string isp = a;
	size_t position;

	if ((position = a.find(":")) != std::string::npos) {
		isp = a.substr(0, position);
	}
	for (int i = 0; i < 20000; i++)
	{
		if (ip[i].addr == isp) {
			ip[i].count++;
			break;
		}
		if (ip[i].addr == "") {
			ip[i].addr = isp;
			ip[i].count = 0;

		}
	}
}
int ids::khondan(string)
{

	fstream fileObj;
	fileObj.open("datas.txt", ios::in);

	if (fileObj.fail()) {
		cout << " file not open" << endl;
		return -1;
	}

	string fileLine;
	int lineTemp = 0;
	while (!fileObj.eof()) {
		getline(fileObj, fileLine);
		
		if (fileLine.find("[**] [") != std::string::npos) {
			lineTemp = 3;
			
		}
		lineTemp--;
		if (lineTemp == 0) {
			string blockData;
			size_t position = 0;
			string delimiter = " ";
			int blockLineTemp = 2;
			cout << fileLine << endl;
			while ((position = fileLine.find(delimiter)) != std::string::npos) {
				blockData = fileLine.substr(0, position);
				blockLineTemp--;

				if (blockLineTemp == 0)
					cout << blockData << endl;

				fileLine.erase(0, position + delimiter.length());
			}
		}
	}
	
}
void ids::show()
{
	for (int i = 0; i < 20000; i++)
	{
		if (ip[i].addr !="")
		{
			cout << ip[i].addr << "-" << ip[i].count;
		}

	}
}
struct my
{
	int countt;
	string aaa;
};
void ids::moratabk()
{

	my iss;
	for (int i = 0; i < 20000; i++)
	{
		for (int j =i+1 ; j < 20000; j++)
		{
			if (ip[j].count>ip[i].count)
			{
				iss.countt = ip[i].count;
				ip[i].count = ip[j].count;
				ip[j].count = iss.countt;
			}
		}

	}

}
class attack:public ids
{
public:

private:

};
class block : public ids
{
public:


private:

};
int main()
{ 
	ids ids;
	int n;
	ids.khondan("datas.txt");
	cout << "namayeshe block haye shabake ba dar nazar gereftan ip haye motabar ba tedad tekrar 1 ra vared kon"<<endl;
cout<< "namayeshe block haye shabake ba dar nazar gereftan ip haye motabar( bdon ) tekrar 2 ra vared kon" << endl;
cout << "baraye serche ip 3 ra vared kon" << endl;
cin >> n;
if (n==1)
	{

	}
if (n==2)
{

}
if (n==3)
{
	string ippp;
	cout << "ip ra vared konid" << endl;
	cin >> ippp;
ids.sercheip(ippp);
}
else
{
	cout << "not found";
}

return 0;




}

