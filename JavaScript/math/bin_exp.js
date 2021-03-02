/*
Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate an using only O(logn) multiplications (instead of O(n) multiplications required by the naive approach).
*/

function binary_expo(a,b,mod)
{
    //End Result Store Here
    let ans=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            //Making the power even
            ans=((ans%mod)*(a%mod))%mod;
            //Decrease the power by 1
            b--;
        }
        else
        {
            //performing sqaure to reduce the power by 2
            a=((a%mod)*(a%mod))%mod;
            //reducing the power by 2.
            b=b/2;
        }
    }
    return ans;
}
console.log(binary_expo(2,3,10000));
//binary_expo(number 1,number 2, mod) (a^b)%mod
//Time Complexity = O (log b)