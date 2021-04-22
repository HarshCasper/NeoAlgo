function floydWarshall(matrice) {
    var temp = [];
    var temp2 = [];
    var temp3 = [];
    
    for (var k = 0; k < matrice.length; k++) {
      for (var i = 0; i < matrice.length; i++) {
        for (var j = 0; j < matrice.length; j++) {
          temp.push(matrice[j][i] * matrice[k][j]);
        }
        if (sum(temp) > 0) {
          temp2.push(1);
        } else {
          temp2.push(0);
        }
        temp = [];
      }
      temp3.push(temp2);
      temp2 = [];
    }
      return temp3;
  }
  
  function sum(arr) {
    return arr.reduce(function(a, b) {
      return a + b;
    }, 0);
  }
  
  //Test Cases: 

  /* Test Case 1:
  var matrice1 = [
    [1, 0, 1, 0, 0, 0, 0, 0],
    [1, 1, 0, 1, 0, 0, 0, 0],
    [1, 0, 1, 0, 0, 0, 0, 0],
    [1, 0, 0, 1, 0, 0, 1, 0],
    [0, 1, 0, 0, 1, 0, 1, 0],
    [0, 0, 1, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 1, 1, 1],
    [0, 0, 0, 0, 1, 0, 0, 1]
  ];

  Output:
  [
    [1, 0, 1, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0, 0, 1, 0],
    [1, 0, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 1, 0, 0, 1, 0, 0],
    [1, 0, 1, 0, 1, 1, 1, 1],
    [0, 1, 0, 0, 1, 0, 1, 1]]
  */
  
 /* Test Case 2:
  var matrice2 = [
    [1, 0, 1, 1], 
    [1, 0, 1, 1], 
    [0, 1, 1, 1], 
    [0, 0, 1, 1]
  ];

  Output:
  [
    [1, 1, 1, 1], 
    [1, 1, 1, 1], 
    [1, 1, 1, 1], 
    [0, 1, 1, 1]]
*/
  