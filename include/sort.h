//
// Created by SuperMiao on 2018/9/26.
//

#ifndef OFFER_SORT_H
#define OFFER_SORT_H

template <class TT>
class Sort
{
public:

    /**
     * bubble sort
     * @param array input array
     * @param len size;
     */
    static void bubbleSort(TT* array, int len)
    {
        bool change = true;
        for(int i = 0; i < len - 1 && change; ++i)
        {
            change = false;
            for(int j = 0; j < len - 1 - i; ++j)
            {
                if(array[j] > array[j+1])
                {
                    swap(array[j], array[j+1]);
                    change = true;
                }
            }
        }
    }


    static void selectSort(TT* array, int len)
    {
        int min = 0;
        for(int i=0; i < len - 1; ++i)
        {
            min = i;
            for(int j = i +1; j < len; ++j)
            {
                if(array[j] < array[min])
                {
                    min = j;
                }
            }

            if(i != min)
            {
                swap(array[i], array[min]);
            }
        }
    }

    static void insertSort(TT* array, int len)
    {
        for(int i=1; i < len; ++i)
        {
            int j = i;
            while (j>0 && array[j] < array[j-1])
            {
                swap(array[j], array[j-1]);
                j--;
            }
        }
    }

    static void quickSort(TT* array, int left, int right)
    {
        if(!array)
        {
          return;
        }

        if(left >= right)
        {
            return;
        }

        int idx = partSort(array, left, right);
        quickSort(array, left, idx-1);
        quickSort(array, idx+1, right);
    }


private:

    static void swap(TT& a, TT& b)
    {
        TT c = a;
        a = b;
        b = c;
    }

    static int partSort(TT* array, int left, int right)
    {
        TT& key = array[right];
        while (left < right)
        {
          while (left < right && array[left] <= key)
          {
            ++left;
          }

          while (left < right && array[right] >= key)
          {
            --right;
          }
          swap(array[left], array[right]);
        }
        swap(array[left], key);
        return left;
    }

};

#endif //OFFER_SORT_H
