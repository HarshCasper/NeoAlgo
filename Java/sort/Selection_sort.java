import java.util.Arrays;

class SelectionSort {
  void selectionSort(int array[]) {
    int size = array.length;

    for (int step = 0; step < size - 1; step++) {
      int min_idx = step;

      for (int i = step + 1; i < size; i++) {

        if (array[i] < array[min_idx]) {
          min_idx = i;
        }
      }
      int temp = array[step];
      array[step] = array[min_idx];
      array[min_idx] = temp;
    }
  }
  public static void main(String args[]) {
    int[] data = { 20, 12, 10, 15, 2 };
    SelectionSort ss = new SelectionSort();
    ss.selectionSort(data);
    System.out.println("Sorted Array in Ascending Order: ");
    System.out.println(Arrays.toString(data));
  }
}
