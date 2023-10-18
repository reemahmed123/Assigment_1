//FCAI _ OOP _ Programming _ 2023 _ Assigment 1
// Program Name: Image Editor.cpp
//Reem Ahmed       20221063   areem9114@gmail.com
//Malak mohammed   20221160   malakmadbouly69@gmail.com
//Mariam Assem     20221142   maryamassem11@gmail.com

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "filters.cpp"
using namespace std;
char choice;  //number of filter which i will choose
void loadImageGS1 ();
void loadImageGS2 ();
void saveImageGS ();
void view_menu();  //menu contains filters
int main()
{
    loadImageGS1();

    while(true) {
        cout<<"Please select a filter to apply or 0 to exit: "<<endl;
        view_menu();
        cout << "choice filter: ";
        cin >> choice;
        if (choice == '0') {
            break;
        } else {
            switch (choice) {
                case '1':
                    Black_and_White_filter_GS();
                    break;
                case '2':
                    Invert_filter_GS();
                    break;
                case '3':
                    loadImageGS2();
                    Merge_filter_GS();
                    break;
                case '4':
                    Flip_filter_GS();
                    break;
                case '5':
                    Rotate_filter_GS();
                    break;
                case '6':
                    darken_and_lighten_filter_GS();
                    break;
                case '7':
                    Detect_edges_filter_GS();
                    break;
                case 'a':
                    Mirror_filter_GS();
                    break;
                case 'd':
                    Crop_filter_GS();
                    break;


            }
        }
    }
    saveImageGS();
}


//_______________
void loadImageGS1 () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, imageGS1);
}
//------------------------------------------------------------------------------------------
void loadImageGS2 () {
    char imageFileName[100];
    // Get gray scale second image file name
    cout << "Please Enter name of image file to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, imageGS2);
}
//------------------------------------------------------------------------------------
void view_menu(){
    cout<<"1- Black and white Filter"<<endl;
    cout<<"2- Invert Filter"<<endl;
    cout<<"3- Merge Filter"<<endl;
    cout<<"4- Flip Filter"<<endl;
    cout<<"5- Rotate Filter"<<endl;
    cout<<"6- Darken and Lighten Filter"<<endl;
    cout<<"7- Detect edges Filter"<<endl;
    cout<<"8- Enlarge Filter"<<endl;
    cout<<"9- Shrink Filter"<<endl;
    cout<<"a- Mirror Filter"<<endl;
    cout<<"b- Suffle Filter"<<endl;
    cout<<"c- Blur Filter"<<endl;
    cout<<"d- Crop Flter"<<endl;
    cout<<"e- Skew Horizontally Filter"<<endl;
    cout<<"f- Skew Vertically Filter"<<endl;
}
//-------------------------------------------------------------------------------------
void saveImageGS () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, imageGS1);
}
//------------------------------------------------------------------------------------------
