#include "filters.h"
#include "bmplib.h"
#include "iostream"
using namespace std;
unsigned char imageGS1[SIZE][SIZE],imageGS2[SIZE][SIZE],direct;
void Black_and_White_filter_GS() {
    //This filter transform gray scale image to black and white image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if (imageGS1[i][j] > 127)
                imageGS1[i][j] = 255;  //pixel will be white
            else
                imageGS1[i][j] = 0;  //pixel will be black
        }
    }
}
//---------------------------------------------------------------------------------------
void Invert_filter_GS(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            // to invert an image we need to get the negative of the image,
            //so we need to subtract every pixel`s value from 255
            imageGS1[i][j] = 255 - imageGS1[i][j];

        }
    }
}
//-----------------------------------------------------------------------------
void Merge_filter_GS(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        {
            imageGS1[i][j]=(imageGS1[i][j]+imageGS2[i][j])/2;
            // to merge mean to ger the average of each two colors
            // ,so I add the first color on the second and divide it by 2 and save it in imageGS1
        }
    }
}
//------------------------------------------------------------------------------
void Flip_filter_GS() {
    //code to flip image vertically or horizontally (the user who choose)

    cout << "flip h(horizontal) or v(vertical) ? " << endl;
    cin >> direct;  //the direct of flip image
    if (direct == 'v') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                //flip image vertically (around x_axis)
                char temp = imageGS1[i][j];          //swap pixels around x axis
                imageGS1[i][j] = imageGS1[SIZE - i][j];
                imageGS1[SIZE - i][j] = temp;
            }
        }

    } else if (direct == 'h') {
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                //flip image horizontally (around y axis)
                char temp = imageGS1[i][j];          //swap pixels around y axis
                imageGS1[i][j] = imageGS1[i][SIZE-j];
                imageGS1[i][SIZE-j] = temp;
            }
        }
    }
}
//-------------------------------------------------------------------------------------------
void Rotate_filter_GS(){
    int angle;
    cout << "Enter the rotation angle (90 , 180 or 270): ";
    cin >> angle;

    if (angle == 90) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j < SIZE; j++) {

                swap(imageGS1[i][j], imageGS1[j][i]); // rotate the image about its main diagonal
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {

                swap(imageGS1[i][j], imageGS1[i][SIZE - 1 - j]); // rotate the image about middle column
            }
        }
    }
    else if (angle == 180) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                int x = imageGS1[i][j];

                imageGS1[i][j] = imageGS1[SIZE - i - 1][j];

                imageGS1[SIZE - i - 1][j] = x;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {

                int x = imageGS1[i][j];

                imageGS1[i][j] = imageGS1[i][SIZE - j - 1];

                imageGS1[i][SIZE - j - 1] = x;
            }
        }

    }
    else if (angle == 270) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {

                swap(imageGS1[i][SIZE - 1 - j], imageGS1[i][j]); // rotate the image about middle column
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j < SIZE; j++) {


                swap(imageGS1[j][i], imageGS1[i][j]); // rotate the image about its main diagonal

            }
        }
    }
}
//---------------------------------------------------------------------------------------------------
void darken_and_lighten_filter_GS(){
    cout<<"if you want it darker enter 1 else enter 2: ";
    int x;
    cin>>x;
    if (x==1)
    {
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
            {
                imageGS1[i][j]=imageGS1[i][j]/4;
                //to darken the image we need to divide each pixel by 4 rather than 2 to make it darker
            }
    }
    else
    {
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
            {
                imageGS1[i][j]=(imageGS1[i][j])/2+63;
                //to lighten the image we divide by  2  to make sure that it doesn't exceed 255
                // then adding 63 because the light colors is from 126 to 255'

            }

    }
}
//---------------------------------------------------------------------------------------
void Mirror_filter_GS() {
    char side;
    cout << "Mirror L(left) or R(right) or U(upper) or D(down) Side?? " << endl;
    cin >> side;
    if (side == 'L') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                //we make each pixel in the right side equal to each pixel in the left side
                imageGS1[i][j] = imageGS1[i][SIZE - j];
            }
        }
    } else if (side == 'R') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                //we make each pixel in the left side equal to each pixel in the right side
                imageGS1[i][j] = imageGS1[i][SIZE - j];
            }
        }
    } else if (side == 'U') {
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //we make each pixel in the lower side equal to each pixel in the upper side
                imageGS1[i][j] = imageGS1[SIZE - i][j];
            }
        }
    } else if (side == 'D') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                //we make each pixel in the upper side equal to each pixel in the lower side
                imageGS1[i][j] = imageGS1[SIZE - i][j];
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------
void Detect_edges_filter_GS() {
    //this filter find the edges of image such as image is drawn with pencil without coloring
    int average=0;
    for(int i=0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            average += imageGS1[i][j];
        }
    }
    average/=(SIZE*SIZE);  //average color of all pixels in image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imageGS1[i][j] > average && imageGS1[i][j + 1] < average) {
                imageGS1[i][j] = 0; //pixel will be black(make edge)
            }
            else if (imageGS1[i][j] < average && imageGS1[i][j + 1] > average) {
                imageGS1[i][j] = 0;  //pixel will be black(make edge)
            }
            else if (imageGS1[i][j] < average && imageGS1[i + 1][j] > average) {
                imageGS1[i][j] = 0;   //pixel will be black(make edge)
            }
            else if (imageGS1[i][j] > average && imageGS1[i + 1][j] < average) {
                imageGS1[i][j] = 0;    //pixel will be black(make edge)
            }
            else if (imageGS1[i][j] < average && imageGS1[i+1][j+1] > average) {
                imageGS1[i][j] = 0;    //pixel will be black(make edge)
            }
            else if (imageGS1[i][j] > average && imageGS1[i+1][j+1] < average) {
                imageGS1[i][j] = 0;     //pixel will be black(make edge)
            }
            else {
                imageGS1[i][j] = 255;   //pixel will be white (not edge)
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------------

void Crop_filter_GS() {
    // this filter crop the image starting from point (x,y) to make square or rectangle of length l and width w
    int x,y,l,w;
    cout<<"Please enter X , Y , L , W : ";
    cin>>x>>y>>l>>w;
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++){
            if(i<x){
                imageGS1[i][j]=255;  //pixel will be white
            }
            if(j<y){
                imageGS1[i][j]=255;   //pixel will be white
            }
            if(i>x+l){
                imageGS1[i][j]=255;   //pixel will be white
            }
            if(j>y+w){
                imageGS1[i][j]=255;      //pixel will be white
            }
        }
    }
}
//------------------------------------------------------------------------------------