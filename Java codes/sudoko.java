// sudoko solver in java 
import java.util.*;


class sudoko{
	static int N = 9;
	public static void printGrid(int[][] grid){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				System.out.print(grid[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();	
	
	}
	public static boolean usedinRow(int[][] grid,int row,int x){
		for(int i=0;i<N;i++){
			if (grid[row][i] == x)
				return true;
			
		}
		return false;
	}
	public static boolean usedinCol(int[][] grid,int col,int x){
		for(int i=0;i<N;i++){
			if (grid[i][col] == x)
				return true;
			
		}
		return false;
	}
	public static boolean usedinBox(int[][] grid,int posx,int posy,int x){
		int startrow = posx-posx%3;
		int startcol = posy-posy%3;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if (grid[i+startrow][j+startcol] == x)
					return true;
			}
			
		}
		return false;
	}
	public static boolean isSafe(int[][] grid,int row,int col,int x){
		if (!usedinRow(grid,row,x) && !usedinCol(grid,col,x) && !usedinBox(grid,row,col,x) && grid[row][col] == 0)
			return true;
		return false;
	}
	
	public static boolean solveSudoko(int[][] grid){
		int row=-1;
		int col=-1;
		boolean allfilled = true;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if (grid[i][j] == 0){
					row = i;
					col = j;
					allfilled = false;
					break;
				}
			}
			if (allfilled == false)
				break;
		}
		if (allfilled == true)
			return true;
		for(int i=1;i<=N;i++){
			if (isSafe(grid,row,col,i)){
				grid[row][col] = i;
				if (solveSudoko(grid))
					return true;
				grid[row][col] = 0;			
				
			}
		}
		return false;
	}
			
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int[][] grid = new int[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				grid[i][j] = input.nextInt();
			}
		}
		System.out.println("Before Solving : ");
		printGrid(grid);
		solveSudoko(grid);
		System.out.println("AfterSolving : ");
		printGrid(grid);	
	}
}





