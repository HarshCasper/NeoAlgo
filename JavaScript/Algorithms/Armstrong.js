process.stdin.resume();
process.stdin.setEncoding("utf-8");
var str = "";
process.stdin.on("data", (data) => {
  str += data;
});
process.stdin.on("end", () => {
  str = str.split("\n");
  var number = str[0];
  var temp = number;
  var answer = 0;
  var rem = 0;
  var n = 0;
  while (temp != 0) {
    temp = Math.floor(temp / 10);
    n++;
  }
  
  temp = number;

  while (temp != 0) {
    rem = Math.floor(temp % 10);
    answer = answer + Math.pow(rem, n);
    temp = Math.floor(temp / 10);
  }

  if (answer == number)
    console.log(number + " is an Armstrong number.");
  else
    console.log(number + " is not an Armstrong number.");

});
