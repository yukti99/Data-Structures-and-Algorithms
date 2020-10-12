#include <stdio.h>

// visiting all petrol pumps in a circular queue
struct petrolPump{	
	int petrol;
	int dist;
};

int printTour(struct petrolPump p[],int n){	

	int start = 0,end = 1;
	int cur_petrol = p[start].petrol - p[start].dist;
	while(end != start || cur_petrol < 0 ){
		
		// removing stations
		while(start != end && cur_petrol < 0){
			cur_petrol -= p[start].petrol - p[start].dist;
			start = (start+1)%n;
			
			if (start==0)
				return -1;
				
		}
		cur_petrol += p[end].petrol - p[end].dist;
		end = (end+1)%n;		
	}
	return start;
}




int main(){
	
	struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};   
    int n = sizeof(arr)/sizeof(arr[0]); 
    int start = printTour(arr, n);   
    (start == -1)? printf("No solution"): printf("Start = %d", start);   
    return 0; 

}
