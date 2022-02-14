// write a function void sort2(double* p , double q)
// that receives two pointers and sorts the values to 
// which they point, if you call sort2(&x,&y) then x <= y
// after the call


void sort2(double* p, double* q) { 
	if (*p > *q) {
	double temp = *p;
	*p = *q;
	*q = temp;
	}
}

void doubleUp() {
	*p = *p *2;
}


int main() {
	double int x = 5.0;
	double int y = 3.0;

	sort2(&x, &y);

	cout << x << ", " << y << endl;

return 0;
}




// write a function double replace_if_greater(double* p, double x)
// that replaces the value to which p points with x if x is greater
// return the old value to which p pointed

double replace_if_greater(double* p, double x) {
	double oldval = *p;
	
	if(*p < x) {
	*p = x;
	}
return oldval;
}

int main() {
	double x = 5.0;
	double y = 1.0;

	double o replace_if_greater(&x, 10.0);
	cout << 	// outputs 10, 5
return 0;
}
