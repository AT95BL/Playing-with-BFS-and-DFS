#include "utility.h"

// Definition of a 'random' number generator...
void nuclearPowerGenerator(const int& n, int* array)
{
	int Xo, a, b, m;

	std::cout << "Please, complete the following formula: x_j+1 = (a * x_j + b) mod m" << std::endl;
	do
	{
		std::cout << "Xo = ";
		std::cin >> Xo;

		std::cout << "a = ";
		std::cin >> a;

		std::cout << "b = ";
		std::cin >> b;

		std::cout << "m = ";
		std::cin >> m;

	} while ((Xo < 0 || Xo > m) || (a < 0 || a > m) || (b < 0 || b > m) || (m < 0));	// Controling the clients input...

	array[0] = Xo;

	for (int i = 1; i < n; i++)															// Forming an
		array[i] = (a * array[i - 1] + b) % m;											// array ...
}

// Definition of an utility function. This function displays an given integers array content...
void displayArray(const int& n, const int* array)										
{
	for (int i = 0; i < n; i++)
		std::cout << array[i] << " ";
}


void heapify(int* array, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		int x = array[i];
		array[i] = array[largest];
		array[largest] = x;

		heapify(array, n, largest);
	}

}


void buildHeap(int* array, int n)
{
	
	int startIdx = (n / 2) - 1;

	for (int i = startIdx; i >= 0; i--) {
		heapify(array, n, i);
	}
}


void heapsort(int* array, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i);							

	buildHeap(array, n);						// Heap building...

	for (int i = n - 1; i >= 0; i--)			// heapified array, builded heap...start the sorting...
	{
		int x = array[0];
		array[0] = array[i];
		array[i] = x;

		std::cout << "Cureent state: ";			// Displaying the current 
		displayArray(n, array);					// array in his current order. Every other iterations displays(in most cases) different..
		std::cout << std::endl;

		BST<int> b(1), * root = nullptr;		// For an array in this state, lets form a BST...
		root = b.insert(root, array[0]);
		for (int i = 1; i < n; i++)
			b.insert(root, array[i]);

		std::cout << "Binary tree for him: ";
		b.printLevelOrder(root);				// Lets see a BST for the current array state...
		std::cout << std::endl;

		heapify(array, i, 0);
	}
}