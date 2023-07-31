#include <vector>
#include <iostream>
using namespace std;
struct PeakData
{
};
void pick_peaks(const vector<int> &v)
{
	vector<int> pos, peaks;
	for (int i = 1; i < v.size() - 1; i++)
	{
		if (v[i] >= v[i - 1] && v[i] > v[i + 1])
		{
			if (v[i] == v[i - 1])
			{
				int a = i;
				int j;
				while (v[i] == v[a])
				{
					j=a;
					a--;
				}
				pos.push_back(j);
				peaks.push_back(v[j]);
			}
			else
			{
				pos.push_back(i);
				peaks.push_back(v[i]);
			}
		}
	}
	for (int i = 0; i < pos.size(); i++)
	{
		cout << pos[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < peaks.size(); i++)
	{
		cout << peaks[i] << "  ";
	}
}

int main()
{
	vector<int> arr = {2,1,3,1,2,2,2,2};
	pick_peaks(arr);
	return 0;
}
/*
#include <vector>

PeakData pick_peaks(const std::vector<int> &v) {
  PeakData result;
  for(int i=1;i<v.size()-1;i++){
    if(v[i]>=v[i-1] && v[i]>v[i+1]){
      if(v[i]==v[i-1]){
        int a=i;
        int j;
        while(v[a]==v[i]){
          j=a;
          a--;
        }
        result.pos.push_back(j);
        result.peaks.push_back(v[j]);
      }else{
        result.pos.push_back(i);
        result.peaks.push_back(v[i]);
      }
    }
  }
  return result;
}
*/