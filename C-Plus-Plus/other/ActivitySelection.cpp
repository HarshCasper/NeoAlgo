/*
* Scheduling a resource among several competing activities 
* Complexity : O(NLog(N))
* Given:
	A single resource
	A set S of N activities, each with:
		si = start time of activity i
		fi = finish time of activity i
* Required:
    Find max-size of compatible activities
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Activity {
	int	start;
	int	end;
};
bool sorting(Activity a, Activity b)
{
	return (a.end < b.end);
}

int main() {
	cout << "Enter Number of Activities: ";
	int N;
	cin >> N;
	Activity* AllActivities = new Activity[N];
	for (int i = 0; i < N; i++) {
		cout << "Enter Start Time of Activity " << i + 1 << ": ";
		int STime; //Start Time
		cin >> STime;
		cout << "Enter Finish Time of Activity " << i + 1 << ": ";
		int FTime; //Finish Time;
		cin >> FTime;
		AllActivities[i].start = STime;
		AllActivities[i].end = FTime;
	}
	//Sorting activities according to finish time in O(NLog(N))
	sort(AllActivities, AllActivities + N, sorting);
	int Size_of_CompatibleActivities = 1;
	int j = 0;
	for (int i = 1; i < N; i++) {
		if (AllActivities[i].start >= AllActivities[j].end)
		{
			Size_of_CompatibleActivities++;
			j = i;
		}
	}
	cout << "Number of Activities that can fit in on resource: " << Size_of_CompatibleActivities << endl;

	/*
	* EX: After Sorting According to Finish Time
	      Activities: 0 1 2 3 4 5 6  7  8  9  10
	*     Start Time: 1 3 0 5 3 5 6  8  8  2  12
	*    Finish Time: 4 5 6 7 8 9 10 11 12 13 14
	* Output : 4
	* Activities: 0 3 7 10
	*/
	return 0;
}
