public class Complex{
	private int real;
	private int imaginer;
	public Complex(){
	    real = 0;
	    imaginer = 0;
	}
	public Complex(int re, int im){
	    real = re;
	    imaginer = im;
	}

/*void Complex::printStatus(){
    cout<<"Real = "<<real<<" Imaginary = "<<imaginer<<endl;
}*/
	public int getReal(){
    	return real;
	}
	public int getImaginer(){
    	return imaginer;
	}
	public void setReal(int re){
    	real = re;
	}
	public void setImaginer(int im){
    	imaginer = im;
	}

	public Complex plus (Complex comp){
	    int re,im;
	    re = real+comp.real;
	    im = imaginer + comp.imaginer;

	    return new Complex(re,im);
	}
	public Complex minus(Complex comp){
	    int re,im;
	    re = real-comp.real;
	    im = imaginer - comp.imaginer;
	    return new Complex(re,im);
	}
	public Complex multiply(Complex comp){
	    int re,im;
	    re = real*comp.real-imaginer*comp.imaginer;
	    im = real*comp.imaginer + imaginer * comp.real;
	    return new Complex(re,im);
	}


}