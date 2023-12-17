int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    // Return gcd of a and b 
    return result; 
} 


// using euclidian's theorem

int gcd(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 
