/*
Same Tree Function
Create a function called bool isSameTree(Tree*); that will take an argument of a tree.It will return a true if the 
argument is the equivalent tree.
So for example, if we have two trees,
insert(‘abc’);
insert(‘def’);
insert(‘ghi’);
insert(‘def’);
insert(‘abc’);
insert(‘ghi’);
These two trees, even though they have different structures, are equivalent, and should return a true.
If we compare these two trees :
insert(‘abc’);
insert(‘ghi’);
insert(‘abc’);
insert(‘def’);
insert(‘ghi’);
They will return a false when sent to the function.
For the Trees, implement the following :
BinaryTreeInterface.h in Listing 15 - 1 on pp. 461 - 463.
BinaryNode.h in Listing 16 - 2 on p. 478.
BinaryNodeTree.h in Listing 16 - 3 on pp. 480 - 482.
NotFoundException.h
PrecondViolatedExcept.h
BinarySearchTree.h in Listing 16 - 4 on pp 502 - 504.

23.SP.CIS.2207.501 Data Structures & Algorithms

@date 04/29/2023
@author  John Durham
*/
#include <iostream>
#include <string>
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "NotFoundException.h"


int menu();
std::string createData();
void printTree(std::string& item);

int main()
{
    int choice = -2;
    BinaryNodeTree<std::string> treeA;
    BinaryNodeTree<std::string> treeB;
    do
    {
        choice = menu();

        
        bool flag = false;
        switch (choice)
        {
        default:
            std::cout << "Invalid selection, please try again." << std::endl;
            break;
        case 0: // Add
        {
            flag = treeA.add(createData());
            if (flag)
                std::cout << "Item added." << std::endl;
            else
                std::cout << "Item could not be added." << std::endl;
            break;
        }
        case 1: // Remove
        {
            std::string toRemoveA = createData();
            try
            {
                flag = treeA.remove(toRemoveA);
                if (flag)
                    std::cout << "Item has been removed from tree." << std::endl;
                else
                    std::cout << "Item(s) could not be removed from tree." << std::endl;
            }
            catch (NotFoundException e)
            {
                std::cout << "Does not exist in tree." << std::endl;
            }
            break;
        }
        case 2: // Print
            treeA.preorderTraverse(printTree);
            break;
        case 3: // Add
        {
            flag = treeB.add(createData());
            if (flag)
                std::cout << "Item added." << std::endl;
            else
                std::cout << "Item could not be added." << std::endl;
            break;
        }
        case 4: // Remove
        {
            std::string toRemoveB = createData();
            try
            {
                flag = treeB.remove(toRemoveB);
                if (flag)
                    std::cout << "Item has been removed from tree." << std::endl;
                else
                    std::cout << "Item(s) could not be removed from tree." << std::endl;
            }
            catch (NotFoundException e)
            {
                std::cout << "Does not exist in tree." << std::endl;
            }
            break;
        }
        case 5: // Print
            treeB.preorderTraverse(printTree);
            break;
        case 6: //compatre
            if (treeA.isSameTree(treeB))
            {
                std::cout << "The two trees are the same!" << std::endl;
            }
            else
            {
                std::cout << "The two trees are NOT! the same." << std::endl;
            }
            treeA.clear();
            treeB.clear();
            break;
        case 7:
            treeA.clear();
            treeB.clear();
            std::cout << "Trees are cleared" << std::endl;
            break;
        case 8:
            std::cout << "Shutting down software..." << std::endl;
            break;
        }
        system("pause");
        system("cls");
    } while (choice != 8);

    return 0;
}



//===========================================================================================


int menu()
{
    int selection;
    std::cout << "==================================================================================" << std::endl;
    std::cout << "|                               Binary Tree isEqual()                            |" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    std::cout << "======= TreeA ============|========= TreeB ============|======= Options ==========" << std::endl;
    std::cout << "|  0. Add to tree         |      3. Add to tree        |    6. Compare trees     |" << std::endl;
    std::cout << "|  1. Remove from tree    |      4. Remove from tree   |    7. Clear trees       |" << std::endl;
    std::cout << "|  2. Print tree          |      5. Print tree         |    8. Quit              |" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    std::cout << "                         Enter your choice: ";
    std::cin >> selection;
    return selection;
}


std::string createData()
{
    std::string data = "";
    std::cout << "Enter data: ";
    std::cin.ignore();
    getline(std::cin, data);
    return data;
}


void printTree(string& item)
{
    std::cout << item << std::endl;
}