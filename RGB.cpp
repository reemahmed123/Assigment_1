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
using namespace std;
unsigned char direct;
unsigned char imageRGB1[SIZE][SIZE][RGB],imageRGB2[SIZE][SIZE][RGB];
char choice;
void loadImageRGB1();
void loadImageRGB2();
void saveImageRGB ();
void Black_and_White_filter_RGB ();
void Invert_filter_RGB();
void Merge_filter_RGB();
void Flip_filter_RGB();
void Rotate_filter_RGB();
void darken_and_lighten_filter_RGB();
void Mirror_filter_RGB();
void Detect_edges_filter_RGB();
void Crop_filter_RGB();
void view_menu();  //menu contains filters
int main()
{
    loadImageRGB1();

    while(true) {
        cout<<"Please select a filter to apply or 0 to exit: "<<endl;
        view_menu();
        cout << "choice filter: ";
        cin >> choice;
        if (choice == 0) {
            break;
        } else {
            switch (choice) {
                case '1':
                    Black_and_White_filter_RGB();
                    break;
                case '2':
                    Invert_filter_RGB();
                    break;
                case '3':
                    Merge_filter_RGB();
                    break;
                case '4':
                    Flip_filter_RGB();
                    break;
                case '5':
                    Rotate_filter_RGB();
                    break;
                case '6':
                    darken_and_lighten_filter_RGB();
                    break;
                case '7':
                    Detect_edges_filter_RGB();
                    break;
                case 'a':
                    Mirror_filter_RGB();
                    break;
                case 'd':
                    Crop_filter_RGB();
                    break;
            }
        }
    }
    saveImageRGB();
}


//_______________
void loadImageRGB1 () {
    char imageFileNamer[100];

    // Get RGB scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileNamer;

    // Add to it .bmp extension and load image
    strcat (imageFileNamer, ".bmp");
    readRGBBMP(imageFileNamer, imageRGB1);
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void loadImageRGB2 () {
    char imageFileNamer[100];
    // Get RGB scale second image file name
    cout << "Please Enter name of image file to merge with: ";
    cin >> imageFileNamer;

    // Add to it .bmp extension and load image
    strcat (imageFileNamer, ".bmp");
    readRGBBMP(imageFileNamer, imageRGB2);
}
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
//_______________
void saveImageRGB () {
    char imageFileNamer[100];

    // Get RGB scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileNamer;

    // Add to it .bmp extension and load image
    strcat (imageFileNamer, ".bmp");
    writeRGBBMP(imageFileNamer, imageRGB1);
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void Black_and_White_filter_RGB(){
    //this filter transform RGB image to black and white
    //in RGB images each pixel consist of 3 sections each section represent degree of (red or green or blue)
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            int aver=0;
            for(int k=0;k<RGB;k++) {  //loop over 3 colors (red green blue) in each pixel
                aver+=imageRGB1[i][j][k];
            }
            aver/=3;  //get the average color of pixel in RGB image
            if((aver)>128){
                imageRGB1[i][j][0]=255;  //make degree of each color =255(will be white)
                imageRGB1[i][j][1]=255;
                imageRGB1[i][j][2]=255;
            }
            else{
                imageRGB1[i][j][0]=0;    //make degree of each color =0(will be black)
                imageRGB1[i][j][1]=0;
                imageRGB1[i][j][2]=0;
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------------
void Flip_filter_RGB() {
    //code to flip image vertically or horizontally (the user who choose)
//in RGB images each pixel consist of 3 sections each section represent degree of (red or green or blue)
    cout << "flip h(horizontal) or v(vertical) ? " << endl;
    cin >> direct;
    if (direct == 'v') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    //flip image vertical (around x_axis)
                    char temp = imageRGB1[i][j][k];    //swap each section in pixel around x axis
                    imageRGB1[i][j][k] = imageRGB1[SIZE - i][j][k];
                    imageRGB1[SIZE - i][j][k] = temp;
                }
            }
        }

    } else if (direct == 'h') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; k++) {
                    //flip image horizontal (around y axis)
                    char temp = imageRGB1[i][j][k];    //swap each section in pixel around y axis
                    imageRGB1[i][j][k] = imageRGB1[i][SIZE - j][k];
                    imageRGB1[i][SIZE - j][k] = temp;
                }
            }
        }
    }
}
//-------------------------------------------------------------------------------------------
void Mirror_filter_RGB() {
    char side;
    cout << "Mirror L(left) or R(right) or U(upper) or D(down) Side?? " << endl;
    cin >> side;
    if (side == 'L') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    //we make each pixel in the right side equal to each pixel in the left side
                    imageRGB1[i][j][k] = imageRGB1[i][SIZE - j][k];
                }
            }
        }
    }
    else if (side == 'R') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; k++) {
                    //we make each pixel in the left side equal to each pixel in the right side
                    imageRGB1[i][j][k] = imageRGB1[i][SIZE - j][k];
                }
            }
        }
    }
    else if (side == 'U') {
        for (int i = SIZE / 2;i<SIZE;i++) {
            for (int j = 0;j<SIZE;j++) {
                for (int k = 0;k<RGB;k++) {
                    //we make each pixel in the lower side equal to each pixel in the upper side
                    imageRGB1[i][j][k] = imageRGB1[SIZE - i][j][k];
                }
            }
        }
    }
    else if (side == 'D') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    //we make each pixel in the upper side equal to each pixel in the lower side
                    imageRGB1[i][j][k] = imageRGB1[SIZE - i][j][k];
                }
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------
void Crop_filter_RGB() {
    // this filter crop the image starting from point (x,y) to make square or rectangle of length l and width w
    int x,y,l,w;
    cout<<"Please enter X , Y , L , W : ";
    cin>>x>>y>>l>>w;
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            for (int k = 0; k < RGB; k++) {
                if (i < x) {
                    imageRGB1[i][j][k] = 255;
                }
                if (j < y) {
                    imageRGB1[i][j][k] = 255;
                }
                if (i > x + l) {
                    imageRGB1[i][j][k] = 255;
                }
                if (j > y + w) {
                    imageRGB1[i][j][k] = 255;
                }
            }
        }
    }
}
//------------------------------------------------------------------------------------
void Detect_edges_filter_RGB() {
    Black_and_White_filter_RGB(); //first I transform image to black and white to make
    for(int i=0;i<SIZE;i++){     //sure that image contains only 2 colors //black=0
        for(int j=0;j<SIZE;j++) {                                        //white=255
            for(int k=0;k<RGB;k++){
                if (abs(imageRGB1[i][j][k] - imageRGB1[i][j + 1][k])==255 ) {
                    //difference between 2 pixels not equal 0 means that each pixel has a different color
                    imageRGB1[i][j][0]=0;  //make color of pixel=0(black)
                    imageRGB1[i][j][1]=0;  //make edge
                    imageRGB1[i][j][2]=0;
                }
                else if (abs(imageRGB1[i][j][k] - imageRGB1[i + 1][j][k]) ==255) {
                    imageRGB1[i][j][0]=0;
                    imageRGB1[i][j][1]=0;
                    imageRGB1[i][j][2]=0;
                }
                else if (abs(imageRGB1[i][j][k] -imageRGB1[i+1][j+1][k])==255) {
                    imageRGB1[i][j][0]=0;
                    imageRGB1[i][j][1]=0;
                    imageRGB1[i][j][2]=0;
                }
                else {
                    imageRGB1[i][j][0]=255;//make color of pixel=255 (not edge)
                    imageRGB1[i][j][1]=255;
                    imageRGB1[i][j][2]=255;
                }
            }
        }
    }
}
//-----------------------------------------------------------------------------------------