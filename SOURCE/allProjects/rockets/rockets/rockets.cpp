#include<iostream>
using namespace std;

struct rocket {
	int id;
	int start;
	int end;
	int score;
};

void swapp(rocket arr[], int start, int end);
void quickSortScore(rocket arr[], int start, int end);
int positionScore(rocket arr[], int start, int end);
void display(rocket [],int start,int end);
void updateScore(rocket[], int start, int end);


int main()
{
	int n,i=0;
	cout << "Enter number of spaceships\n";
	cin >> n;
	cout << "Enter info for spaceships\n";
	rocket *spaceship = new rocket[n];
	while (i < n) {
		cin >> spaceship[i].id >> spaceship[i].start >> spaceship[i].end;
		spaceship[i].score = 0;
		i++;
	}
	updateScore(spaceship, 0, n);
	display(spaceship, 0, n);
	quickSortScore(spaceship, 0, n - 1);
	display(spaceship, 0, n );
    return 0;
}
//aux funstions////////////////////////////////////////////
void updateScore(rocket rock[], int start, int end){
	int i, j;
	for (i = 0; i < end -1; i++) {
		for (j = i+1; j < end; j++) {
			if (rock[i].start < rock[j].start && rock[i].end > rock[j].end) {
				rock[i].score++;
			}
		}
	}
}
void display(rocket rock[], int start, int end) {
	cout << endl;
	while (start < end) {
		cout << rock[start].id << " " << rock[start].score << endl;
		start++;
	}
}
void swapp(rocket arr[], int start, int end)
{
	rocket temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}
void quickSortScore(rocket arr[], int start, int end)
{
	if (start < end)
	{
		int pivotPos = positionScore(arr, start, end);
		quickSortScore(arr, start, pivotPos - 1);
		quickSortScore(arr, pivotPos + 1, end);
	}

}
int positionScore(rocket arr[], int start, int end)
{
	int smallIndex;
	swapp(arr, start, (start + end) / 2);
	rocket pivot = arr[start];
	smallIndex = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (pivot.score > arr[i].score)
		{
			smallIndex++;
			swapp(arr, i, smallIndex);
		}
	}
	swapp(arr, start, smallIndex);
	return smallIndex;
}