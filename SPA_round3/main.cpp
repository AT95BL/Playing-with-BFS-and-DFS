#include "utility.h"

using namespace std::chrono;

int main()
{
	BST<int> b(1), * root = nullptr;                        

    int n,* array;

    char c;

    auto start = high_resolution_clock::now();              //  Run time measure starting point...

    do
    {
        
        do
        {
            std::cout << "Start y/n:";                      //  Asking a client...To start the test or to leave the application...
            std::cin >> c;

        } while ((c != 'y') && (c != 'n'));                 // Answer to this question can only be 'Yes or No' ...

        if (c == 'y')                                                 // For the 'Y' case...
        {

            do { std::cout << "n="; std::cin >> n; } while (n < 1);     // Asking a client...How much numbers he wants to store in an array...
            array = new int[n];
            nuclearPowerGenerator(n, array);                            // Storing 'n' random numbers for the client...

            Sleep(5000);                                                // Before showing the results, let him(client...) seee the input values...

            root = b.insert(root, array[0]);                            // BST formation starting point
            for (int i = 1; i < n; i++)
                b.insert(root, array[i]);                               // and forming the BST for this case...

            std::cout << "Inorder: " << std::endl;
            b.inorder(root);                                            // Display the BST in  'Inorder' order...

            std::cout << std::endl << "Heap sorting: " << std::endl;    
            heapsort(array, n);                                         // Heapsorting starting point...

            std::cout << "Sorted array: " << std::endl;
            displayArray(n, array);                                     // Display an array for the client...


            std::cout << std::endl << "In level order: " << std::endl;  
            b.printLevelOrder(root);                                     // Display BST level by level...        

        }

        std::cout << std::endl;

    } while (c != 'n');

    auto stop = high_resolution_clock::now();                           // End for the costumer service part...Run time measure ending point...

    auto duration = duration_cast<microseconds>(stop - start);          // Calculating total time...

    std::cout << "\nTime taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}