public class LinearSearch<T>
{
    public static int Search(T[] array, T element)
    {
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i].Equals(element))
            {
                return i;
            }
        }

        return -1;
    }
}

