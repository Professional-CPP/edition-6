using MyCppLibrary;

namespace MyLibrary
{
    public class MyClass
    {
        public double DoubleIt(double value)
        {

            return value * 2.0;
        }

        public double TripleIt(double value)
        {
            // Ask C++ to triple it.
            MyCppRefClass cppRefClass = new MyCppRefClass();
            return cppRefClass.TripleIt(value);
        }
    }
}
