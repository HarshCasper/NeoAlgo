import java.util.Objects;


/**
 * 
 * This is an implementation of Complex numbers in Java. 
 * 
 * @author Ricardo Prins
 * @since 12-01-2019
 * @version 1.0.0
 * 
 */
public class Complex {
    private double real;   // the real part
    private double imaginary;   // the imaginary part

    /**
     * Creates a complex number.
     * @param real
     * @param imaginary
     */
    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }
    public double getReal() {
        return real;
    }
    public double getImaginary() {
        return imaginary;
    }
    public void setReal(double real) {
        this.real = real;
    }
    public void setImaginary(double imaginary) {
        this.imaginary = imaginary;
    }
    /**
     * @return modulus/absolute value of a given complex number
     */
    public double abs() {
        return Math.hypot(real, imaginary);
    }
    /**
     * @return angle/phase/argument, normalized to be between -pi and pi
     */
    public double phase() {
        return Math.atan2(imaginary, real);
    }
    /**
     * @param b complex to be added
     * @return new Complex object whose value is (this + b)
     */
    public Complex add(Complex b) {
        Complex a = this;
        double real = a.real + b.real;
        double imag = a.imaginary + b.imaginary;
        return new Complex(real, imag);
    }
    /**
     * Static version of add method
     * @param a
     * @param b
     * @return
     */
    public static Complex add(Complex a, Complex b) {
        double real = a.real + b.real;
        double imag = a.imaginary + b.imaginary;
        return new Complex(real, imag);
    }
    /**
     * @param b
     * @return a new Complex object whose value is (this - b)
     */
    public Complex subtract(Complex b) {
        Complex a = this;
        double real = a.real - b.real;
        double imag = a.imaginary - b.imaginary;
        return new Complex(real, imag);
    }
    /**
     * @param b
     * @return a new Complex object whose value is (this * b)
     */
    public Complex multiply(Complex b) {
        Complex a = this;
        double resultReal = a.real * b.real - a.imaginary * b.imaginary;
        double resultImaginary = a.real * b.imaginary + a.imaginary * b.real;
        return new Complex(resultReal, resultImaginary);
    }
    /**
     * @param b
     * @return Complex a/b
     */
    public Complex divide(Complex b) {
        Complex a = this;
        return a.multiply(b.reciprocal());
    }
    /**
     * @return a new Complex object whose value is the complex exponential of this
     */
    public Complex exp() {
        return new Complex(Math.exp(real) * Math.cos(imaginary), Math.exp(real) * Math.sin(imaginary));
    }

    /**
     * @return a new Complex object whose value is the complex sine of this
     */
    public Complex sin() {
        return new Complex(Math.sin(real) * Math.cosh(imaginary), Math.cos(real) * Math.sinh(imaginary));
    }

    /**
     * @return a new Complex object whose value is the complex cosine of this
     */
    public Complex cos() {
        return new Complex(Math.cos(real) * Math.cosh(imaginary), -Math.sin(real) * Math.sinh(imaginary));
    }

    /**
     * @return a new Complex object whose value is the complex tangent of this
     */
    public Complex tan() {
        return sin().divide(cos());
    }
    /**
     * @param alpha
     * @return a new object whose value is (this * alpha)
     */
    public Complex scale(double alpha) {
        return new Complex(alpha * real, alpha * imaginary);
    }
    /**
     * @return a new Complex object whose value is the conjugate of this
     */
    public Complex conjugate() {
        return new Complex(real, -imaginary);
    }
    /**
     * @return a new Complex object whose value is the reciprocal of this
     */
    public Complex reciprocal() {
        double scale = real * real + imaginary * imaginary;
        return new Complex(real / scale, -imaginary / scale);
    }
    @Override
    public boolean equals(Object x) {
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Complex that = (Complex) x;
        return (this.real == that.real) && (this.imaginary == that.imaginary);
    }
    @Override
    public int hashCode() {
        return Objects.hash(real, imaginary);
    }
    @Override
    public String toString() {
        if (imaginary == 0) return real + "";
        if (real == 0) return imaginary + "i";
        if (imaginary < 0) return real + " - " + (-imaginary) + "i";
        return real + " + " + imaginary + "i";
    }
}