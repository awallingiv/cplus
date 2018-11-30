#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void mainMenu();
void manipulateMenu();
//void generateMenu();
vector<vector<int>> readFile();
void convertToPicture(vector<vector<int> > &image);
void rotateRight(vector<vector<int> > &image);
//void convertToPictureDynamic(int image[int][int]);
//void rotateRightDynamic(int original[int][int], int, int);
void printContents(vector<vector<int> > image);



struct Pixels
{
	int red;
	int green;
	int blue;
};

int main()
{
	//mainMenu();
	int row = 5;
	int column = 4;
	vector<vector<int>> original;
	original.assign(row, vector<int>(column, 0));
	
	

	int counter = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < column; y++)
		{
			original[x][y] = counter;
			counter++;
		}
	}
	
	cout << "\nTable should be filled." << endl;
	
	for (int c = 0; c < row; c++)
	{
		for (int r = 0; r < column; r++)
		{
			cout << "Box " << c << "," << r << " contains " << original[c][r] << endl;
		}
	}
		
	convertToPicture(original);
		
	return 0;
}

void mainMenu()
{
	
	char choice;
	cout << "Please select an option from the following menu: " << endl;
	cout <<"\n";
	cout <<"Manipulate image [m]" << endl;
	cout <<"Generate images [g]" << endl;
	cout <<"Quit [q]" << endl;
	cout << "\n";
	cout << "Enter your choice: ";
	cin >> choice;
		
	switch (choice)
	{
		case 'm':// manipulateMenu();
		break;
		case 'g': //generateMenu();
		break;
		case 'q':
		break;
	}
}

void manipulateMenu()
{
	char choice;
	cout << "Please select an option from the following menu: " << endl;
	cout <<"\n";
	cout <<"Filter [s]" << endl;
	cout <<"Crop [c]" << endl;
	cout <<"Rotate [r]" << endl;
	cout <<"Quit [q]" << endl;
	cout << "\n";
	cout << "Enter your choice: ";
	cin >> choice;
		
	switch (choice)
	{
		case 's':
		break;
		case 'c':
		break;
		case 'r':
		break;
		case 'q': mainMenu();
		break;
	}
}

void generateMenu()
{
	
}

vector<vector<int>> readFile()
{
	string filename;
	cout << "\nPlease enter filename: ";
	cin >> filename;
	
	fstream imgFile (filename.data(), ios::in | ios::binary);
	
	if (!imgFile)
	{
		cout << "\nThe image file was not found." << endl;
	}
	
	string line;
	int linecount = 0;
	string srow, scol;
	int row, column;
	
	while (!imgFile.fail())
	{
		getline(imgFile, line);
		if (linecount == 1) //when we get to the second line (which contains dimensions)
		{
			istringstream ss(line); //used to split string by spaces
			//read a "word"(first set of numbers)
			string word;
			ss >> word;
			srow = word;
			ss >> word;
			scol = word;
			//now we have 2 separate strings, and must convert to ints
			row = stoi(srow);
			column = stoi(scol);
		}
	}
	
}

void convertToPicture(vector<vector<int> > &image)
{
	//cout << "\nSize of vector rows is: " << image.size() << endl;
	//cout << "\nSize of vector columns is: " << image[0].size() << endl;
	int r = image.size();
	int c = image[0].size(); //this only works because it gets the size (amount of columns) of first row
	
	for(int y = 0; y < r; y++)
	{
        for (int x = 0; x < c; x++) 
		{
            cout << image[y][x] << " ";
        }
        cout << endl;
    } 
    cout << endl << endl;
}

void rotateRight(vector<vector<int> > &image)
{
	int r = image.size();
	int c = image[0].size();
	
   // int rotated[r][c];
    for (int y = 0; y < r; y++)
	{
        for (int x = 0; x < c; x++)
		{
            image[x][3-y] = image[y][x];
        } 
    } 

    convertToPicture(image);
}

//void printContents(vector<vector<int> > image)
//{
//	int r = image.size();
//	int c = image[0].size();
//	
//	
//}


//void convertToPictureDynamic(int image[int r][int c])
//{
//    for(int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; x++) {
//            cout << image[i][j] << " ";
//        } // end i for loop
//        cout << endl;
//    } // end j for loop
//    cout << endl << endl;
//}
