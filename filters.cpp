#include "filters.h"
#include "bmplib.h"
#include "iostream"
using namespace std;
unsigned char imageGS1[SIZE][SIZE],imageGS2[SIZE][SIZE],imgGS1[size][SIZE],,imgGS2[size][SIZE],imgGS3[size][SIZE],direct;
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
void Enlarge_filter_GS(){
    unsigned char q1[SIZE][SIZE];
    int quarter;
    cout<<"Enter quarter number that you want to enlarge: ";
    cin>>quarter;
    if(quarter == 1){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                q1[i][j] = imageGS1[(i / 2) ][(j / 2) ];
                //Create a new image with the same size as the original image that contains the first quadrant
                // that whose rows and columns start from pixel 0 to pixel 127
            }
        }
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                imageGS1[i][j] = q1[i][j];
            }
        }
    }else if(quarter == 2){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                q1[i][j] = imageGS1[i/2][(j/2) + 128] ;
                //Create a new image with the same size as the original image that contains the second quadrant
                // that whose rows starts from pixel 0 to 127 and columns starts from pixel 128 to pixel 255
            }
        }
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                imageGS1[i][j] = q1[i][j];
            }
        }
    } else if(quarter == 3){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                q1[i][j] = imageGS1[(i/2) + 128][(j/2)] ;
                //Create a new image with the same size as the original image that contains the third quadrant
                // that whose rows starts from pixel 128 to 255 and columns starts from pixel 0 to pixel 127
            }
        }
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                imageGS1[i][j] = q1[i][j];
            }
        }
    }else if(quarter == 4){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                q1[i][j] = imageGS1[(i / 2) + 128][(j / 2) + 128];
                //Create a new image with the same size as the original image that contains the fourth quadrant
                // that whose rows and columns start from pixel 128 to pixel 255
            }
        }
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                imageGS1[i][j] = q1[i][j];
            }
        }
    }
}
void shrink gs(){
     for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
            {
               imgGS2[i][j]=255;
            }
        int x;
        cout<<"enter 1 if you want to shrink to half or two to third or three to quarter";
        cin>>x;
        if(x==1) {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++) {
                    imgGS2[i / 2][j / 2] = imgGS1[i][j];
                }
        }
        else if(x==2) {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++) {
                    imgGS2[i / 3][j / 3] = imgGS1[i][j];
                }
        }
        else  {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++) {
                    imgGS2[i / 4][j / 4] = imgGS1[i][j];
                }
        }
}
//------------------------------------------------------------------------------------------
void Shuffle_filter_GS(){

    unsigned char q1[SIZE][SIZE],q2[SIZE][SIZE],q3[SIZE][SIZE],q4[SIZE][SIZE];

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {

            q1[i][j] = imageGS1[i][j]; //Create a new image that contains the first quadrant
        }
    }

    for (int i = 0; i < 128; i++) {
        for (int j = 128; j < SIZE; j++) {

            q2[i][j] = imageGS1[i][j]; //Create a new image that contains the second quadrant
        }
    }

    for (int i = 128; i < SIZE; i++) {
        for (int j = 0; j < 128; j++) {

            q3[i][j] = imageGS1[i][j]; //Create a new image that contains the third quadrant
        }
    }

    for (int i = 128; i < SIZE; i++) {
        for (int j = 128; j < SIZE; j++) {

            q4[i][j] = imageGS1[i][j]; //Create a new image that contains the fourth quadrant
        }
    }

    cout<<"Enter the order you want for the quarters in the new image: ";

    int order[4];

    for(int i = 0; i < 4 ; i++){

        cin>>order[i];
    }

    for(int h = 0; h < 4; h++){

//iterate through the 4 quarters, and for each quarter fill in the quarter that the user wants

        if ((h + 1) == 1) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    // iterate through the first quarter
                    if (order[h] == 1) {

                        imageGS1[i][j] = q1[i][j];

                    } else if (order[h] == 2) {

                        imageGS1[i][j] = q2[i][j + 128];

                    } else if (order[h] == 3) {

                        imageGS1[i][j] = q3[i + 128][j];

                    } else if (order[h] == 4) {

                        imageGS1[i][j] = q4[i + 128][j + 128];
                    }

                }

            }
        } else if ((h + 1) == 2) {
// iterate through the second quarter
            for (int i = 0; i < 128; i++) {
                for (int j = 128; j < SIZE; j++) {

                    if (order[h] == 1) {

                        imageGS1[i][j] = q1[i][j - 128];

                    } else if (order[h] == 2) {

                        imageGS1[i][j] = q2[i][j];

                    } else if (order[h] == 3) {

                        imageGS1[i][j] = q3[i + 128][j - 128];

                    } else if (order[h] == 4) {

                        imageGS1[i][j] = q4[i + 128][j];
                    }

                }

            }
        } else if ((h + 1) == 3) {
// iterate through the third quarter
            for (int i = 128; i < SIZE; i++) {
                for (int j = 0; j < 128; j++) {

                    if (order[h] == 1) {

                        imageGS1[i][j] = q1[i - 128][j];

                    } else if (order[h] == 2) {

                        imageGS1[i][j] = q2[i - 128][j + 128];

                    } else if (order[h] == 3) {

                        imageGS1[i][j] = q3[i][j];

                    } else if (order[h] == 4) {

                        imageGS1[i][j] = q4[i][j + 128];
                    }

                }

            }
        } else if ((h + 1) == 4) {
// iterate through the fourth quarter
            for (int i = 128; i < SIZE; i++) {
                for (int j = 128; j < SIZE; j++) {

                    if (order[h] == 1) {

                        imageGS1[i][j] = q1[i - 128][j - 128];

                    } else if (order[h] == 2) {

                        imageGS1[i][j] = q2[i - 128][j];

                    } else if (order[h] == 3) {

                        imageGS1[i][j] = q3[i][j - 128];

                    } else if (order[h] == 4) {

                        imageGS1[i][j] = q4[i][j];
                    }

                }

            }
        }
    }

}
//----------------------------------------------------------------------------
void blur-GS()
    {
       for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
            {
                if(!i and !j)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j+1]+imgGS1[i+1][j]+imgGS1[i+1][j+1])/4;
                }
                else if(!i and j==255)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j-1]+imgGS1[i+1][j]+imgGS1[i+1][j-1])/4;
                }
                else if(!j and i==255)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j+1]+imgGS1[i-1][j]+imgGS1[i-1][j-1])/4;
                }
                else if (i==255 and j==255)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j-1]+imgGS1[i-1][j]+imgGS1[i-1][j-1])/4;
                }
                else if (!i)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j+1]+imgGS1[i+1][j]+imgGS1[i+1][j+1]+imgGS1[i-1][j]+imgGS1[i-1][j+1])/6;
                }
                else if (i==255)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j+1]+imgGS1[i][j-1]+imgGS1[i-1][j+1]+imgGS1[i-1][j]+imgGS1[i-1][j-1])/6;
                }
                else if(!j)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i][j+1]+imgGS1[i][j-1]+imgGS1[i+1][j+1]+imgGS1[i+1][j]+imgGS1[i+1][j-1])/6;
                }
                else if(j==255)
                {
                    imgGS1[i][j]=(imgGS1[i][j]+imgGS1[i+1][j]+imgGS1[i-1][j]+imgGS1[i][j-1]+imgGS1[i-1][j-1]+imgGS1[i+1][j-1])/6;
                }
                else {

                        imgGS1[i][j] = (imgGS1[i][j]+imgGS1[i+1][j]+imgGS1[i-1][j]+imgGS1[i][j-1]+imgGS1[i][j+1]+imgGS1[i-1][j-1]+imgGS1[i-1][j+1]+imgGS1[i+1][j-1]
                                +imgGS1[i+1][j+1])/9;

                }
            }
        showGSBMP(imgGS1);


    }
}
void skew_vertically-GS(){
     cout<<"enter the degree you want the image to be skewed by: ";
    double degree;cin>>degree;
    degree=degree*(M_PI / 180);
    double x = 265 / (1+(1/tan(degree)));
    for(int i=0 ;i<SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++)
        {
            imgGS2[i][j]=255;
            imgGS3[i][j]=255;
        }
    double step = SIZE - x;
    double move  = step/SIZE;
    for(int i=0 ;i<SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++)
        {
            imgGS2[i][j*int (x)/SIZE]=imgGS1[i][j];
        }


    for(int i=0 ;i<SIZE ; i++)
        for(int j = 0 ; j < SIZE ; j++)
        {
            imgGS3[i][j]=imgGS2[i][j-int(step)];
        }
    step-=move;

    showGSBMP(imgGS3);
}
}
void Skew_Horizontally_filter_GS(){

    cout<<"Enter the degree you want the image to be skewed by: ";

    double degree;
    cin>>degree;
    degree = degree * (M_PI / 180); //Convert the angle from degrees to radians

    double x = 256 / (1 + (1 / tan(degree)));

    unsigned char image2[SIZE][SIZE] , image3[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image2[i][j] = 255;
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image2[i][( j * int(x) ) / SIZE] = imageGS1[i][j]; //Shrink the image by a value of x
            // to avoid it from exceeding the original image size
        }
    }

    double step = SIZE - x;  // The point at which I start pixel placement
    double move = step / SIZE; //Number of steps

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image3[i][j + int(step)] = image2[i][j]; // shifting the image
        }
        step -= move;
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            imageGS1[i][j] = image3[i][j];
        }
    }

}
