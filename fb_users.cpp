//************************************************************************************//
/*Example.
#id Name     Friends_id
0   Avik     {1,2}
1   Barath   {2,3,4,5,6}
2   chetty   {4,5,6,7,8}
3   Dinash   {6,7,8,9,10,11,12,13,14}

Input list= { 
            struct{0,{1,2}}, 
            struct{1,{2,3,4,5,6}}, 
            struct{2,{4,5,6,7,8}},
            struct{3,{6,7,8,9,10,11,12,13,14}} 
            }
            
1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
2. Uniqe friends of Avik (0) -> {1} so the answer should be 1
3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
    
//----------------Do not uncommand or recreate struct fbUser------------------------------------------//
//Structure for facebook users, each hase fb unique id -> userID and list of
//friends -> friends
struct fbUser{
    int userID;
    list<int> friends;
};
//------------------------------------------------------------------------------//
    
*/
//************************************************************************************//


//List of Headers
#include<iostream>
#include "header.h"
#include <list>
#include <map>
using namespace std;


//------------------------------------------------------------------------------//


//    **Spcace to add you own functions**           //









//------------------------------------------------------------------------------//
//1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
//---------------------------------------------------------------------------------//
int find_mutual_friends(int person1_id,int person2_id, list<fbUser> list_of_fbusers)
{
    int mutual_friends=0;
    //-----------------------------------------//
    //Please write your code here
    map<int,bool> map1;
    map<int,bool> map2;
    
    list<int>::iterator it;
    list<fbUser>::iterator it1 = list_of_fbusers.begin();
    list<fbUser>::iterator it2 = list_of_fbusers.begin();

    while(it1->userID != person1_id){
        it1++;
    }

    while(it2->userID != person2_id){
        it2++;
    }

    for(it = it1->friends.begin(); it != it1->friends.end(); it++){
        map1[*it] = true;
    }
    
    for(it = it2->friends.begin(); it != it2->friends.end(); it++){
        map2[*it] = true;
    }
    
    map<int,bool>::iterator itm;
    for(itm = map1.begin(); itm != map1.end(); itm++){
        if(map2[itm->first] == true)
            mutual_friends += 1;
    }
    
    //-----------------------------------------//
    return mutual_friends;
}



//---------------------------------------------------------------------------------//
//2, Uniqe friends of Avik (0) -> {1} so the answer should be 1
//---------------------------------------------------------------------------------//
int find_uniq_friends(int person_id, list<fbUser> list_of_fbusers)
{
    int uniq_friends=0;
    //-----------------------------------------//
    //Please write your code here
    
    map<int,bool> map1;
    
    list<int>::iterator it;
    
    list<fbUser>::iterator it1 = list_of_fbusers.begin();

    while(it1->userID != person_id){
        it1++;
    }

    for(it = it1->friends.begin(); it != it1->friends.end(); it++){
        map1[*it] = true;
    }
    uniq_friends = map1.size();
    list<fbUser>::iterator it2;
    for(it2 = list_of_fbusers.begin(); it2 != list_of_fbusers.end(); it2++){
        list<int>:: iterator it3;
        if(it2->userID != person_id){
            for(it3 = it2->friends.begin(); it3 != it2->friends.end(); it3++){
                if(map1[*it3] == true){
                    uniq_friends -= 1;
                }
        }
            
        }
    }
    
    
    //-----------------------------------------//
    return uniq_friends;
}


//------------------------------------------------------------------------------//
/*3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
*/
//------------------------------------------------------------------------------//
//Funciton to find the number of strangers
int find_strangers(int person_id, list<fbUser> list_of_fbusers)
{
    int strangers=0;
    //-----------------------------------------//
    //Please write your code here
    
    int total_users;
    map<int,bool> map1;
    map<int,bool> map2;
    list<fbUser>::iterator it;
    list<int>::iterator it1;
    
    for(it = list_of_fbusers.begin(); it != list_of_fbusers.end(); it++){
        for(it1 = it->friends.begin(); it1 != it->friends.end(); it1++){
            map1[*it1] = true;
        }
    }
    
    total_users = map1.size();
    
    list<fbUser>::iterator it2 = list_of_fbusers.begin();
    list<int>::iterator it5;

    while(it2->userID != person_id){
        it2++;
    }
    list<int>::iterator it3;

    for(it3 = it2->friends.begin(); it3 != it2->friends.end(); it3++){
        map2[*it3] =  true;
        list<fbUser>::iterator it4 = list_of_fbusers.begin();
        while(it4->userID != *it3){
        it4++;
    }

        for(it5 = it4->friends.begin(); it5 != it4->friends.end(); it5++){
            map2[*it5] = true;
        }
        
    }
    strangers = total_users - map2.size();
    //-----------------------------------------//
    return strangers;
}
//------------------------------------------------------------------------------//