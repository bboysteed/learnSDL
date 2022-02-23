//
// Created by steed on 2022/2/19.
//
#include "SDL.h"
#include "SDL_image.h"
#include "vector"
#include "iostream"
using namespace std;
vector<vector<vector<int>>> allAns;
vector<vector<int>> sulo;
int start_[2] = {0, 0};
int end_[2] = {2, 0};
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
void dfs(int arr[3][4], const int idx[2]) {
//    bool flag;
    int r = idx[0];
    int c = idx[1];

    if(r==end_[0]&&c==end_[1]){  //如果该点是终点
        allAns.push_back(sulo);
        return;
    }
    //不是终点
    if (r + 1 < 3 && arr[r + 1][c] == 1) {
        int tmp[2] = {(r + 1), c};
        arr[r+1][c] = 0;
        sulo.push_back({(r+1),c});
        dfs(arr, tmp);
        arr[r+1][c] = 1;
        sulo.pop_back();
//        flag = true;
//        sulo.pop_back();
    }
    if (r - 1 >= 0 && arr[r - 1][c] == 1) {
        int tmp[2] = {(r - 1), c};
        arr[r-1][c] = 0;
        sulo.push_back({(r-1),c});
        dfs(arr, tmp);
        arr[r-1][c] = 1;
        sulo.pop_back();
//        flag = true;

//        sulo.pop_back();
    }
    if (c + 1 < 4 && arr[r][c + 1] == 1) {
        int tmp[2] = {r, (c + 1)};
        arr[r][c+1] = 0;
        sulo.push_back({r,(c+1)});
        dfs(arr, tmp);
        arr[r][c+1] = 1;
        sulo.pop_back();
//        flag = true;

//        sulo.pop_back();
    }
    if (c - 1 >= 0 && arr[r][c - 1] == 1) {
        int tmp[2] = {r, (c - 1)};
        arr[r][c-1] = 0;
        sulo.push_back({r,(c-1)});
        dfs(arr, tmp);
        arr[r][c-1] = 1;
        sulo.pop_back();
//        flag = true;

//        sulo.pop_back();
    }
//    if(!flag){
//        arr[r][c]
//    }

}

void PutPicture(const string path,int x, int y, int w, int h,SDL_Renderer *gRenderer){
    SDL_Rect tmp = {x,y,w,h};
    SDL_Surface * res = IMG_Load(path.c_str());
//    SDL_RenderClear(gRenderer);
    SDL_Texture *gTexture = SDL_CreateTextureFromSurface(gRenderer,res);
    SDL_RenderCopy(gRenderer,gTexture, nullptr, &tmp);

//    res = SDL_ConvertSurface(res,screen->format,0);
//    SDL_BlitScaled(res, nullptr,screen,&tmp);
//    return res;
//    SDL_Surface  *bg = IMG_Load("/Users/steed/CLionProjects/leetcode/kongbai.png");
}


void init(){
    SDL_Init(SDL_INIT_EVERYTHING);
}
void creatBground(){

}
void drawLine(){
//    SDL_Rect fillRect1 = { 45, 45, 100, 10 };
//    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
////    SDL_RenderClear( gRenderer );
//    SDL_RenderFillRect( gRenderer, &fillRect1 );
//
//    fillRect1 = { 145, 45, 10, 100 };
//    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
////    SDL_RenderClear( gRenderer );
//    SDL_RenderFillRect( gRenderer, &fillRect1 );
//    fillRect1 = { 145, 145, 100, 10 };
//    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
////    SDL_RenderClear( gRenderer );
//    SDL_RenderFillRect( gRenderer, &fillRect1 );
//    SDL_RenderPresent(gRenderer);
}
int main(int argc, char* args[]) {
    init();
    SDL_Surface* apple = nullptr;
//    SDL_Surface* screen = nullptr;
    SDL_Window* win = nullptr;
    SDL_Renderer * gRenderer = nullptr;
    SDL_Texture * gTexture = nullptr;
    win = SDL_CreateWindow("example",100,100,400,300,SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!gRenderer){
        cout<<"error in create SDL_Renderer:"<<SDL_GetError()<<endl;
    }
    PutPicture("/Users/steed/CLionProjects/leetcode/kongbai.png",0,0,400,300,gRenderer);


    PutPicture("/Users/steed/CLionProjects/leetcode/redApple.png",20,20,60,60,gRenderer);
////    SDL_BlitSurface(apple, nullptr, screen, nullptr);
//
    PutPicture("/Users/steed/CLionProjects/leetcode/greenApple.png",20,220,60,60,gRenderer );
////    apple = SDL_ConvertSurface(apple,screen->format,0);
////    apple = loadIMG2Screen("/Users/steed/CLionProjects/leetcode/yellowApple.png",20,120,60,60,screen);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",120,20,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",220,20,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",320,20,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",20,120,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",120,120,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",220,120,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",320,220,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",120,220,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",220,220,60,60,gRenderer);
    PutPicture("/Users/steed/CLionProjects/leetcode/yellowApple.png",320,120,60,60,gRenderer );
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_Rect line{
            

    } ;
    SDL_RenderFillRect( gRenderer, &line );



//    SDL_Texture *tex = nullptr;
//    tex = SDL_CreateTextureFromSurface(ren, apple);
//    SDL_RenderClear(ren);
//    SDL_RenderCopy(ren, tex, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    bool quit = false;
    SDL_Event e;

    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
                //User presses a key
            else if (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        cout<<"up"<<endl;
//                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                        break;

                    case SDLK_DOWN:
//                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                        break;

                    case SDLK_LEFT:
//                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                        break;

                    case SDLK_RIGHT:
//                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                        break;

                    default:
//                        gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                        break;
                }
            }
        }
    }

//    SDL_Delay(2000);
//    SDL_DestroyTexture(tex);
//    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;



    int arr[3][4] = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1}
    };


    arr[start_[0]][start_[1]] = 0;
    sulo.push_back({start_[0],start_[1]});
    dfs(arr, start_);


    for (const auto &ans: allAns) {
        for (const auto &item: ans) {
            cout<<"("<<item[0]<<","<<item[1]<<") -> ";
        }
        cout << endl;
    }


}