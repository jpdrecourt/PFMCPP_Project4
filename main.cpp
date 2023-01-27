/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
        REMEMBER: if a member function doesn't modify any member variables of the class it exists in, what qualifier can we add to that function's signature?
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

#include <iostream>

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!

*/

struct A {};
struct HeapA
{ 
    HeapA() : a(new A) {}
    ~HeapA()
    {
        delete a;
    }
    A* a = nullptr;
};

struct FloatType
{
    FloatType(float f) : value( new float(f) ){}
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }
    FloatType& add( float rhs );
    FloatType& add( int rhs );
    FloatType& add( double rhs );

    FloatType& subtract( float rhs );
    FloatType& subtract( int rhs );
    FloatType& subtract( double rhs );

    FloatType& multiply( float rhs );
    FloatType& multiply( int rhs );
    FloatType& multiply( double rhs );
    
    FloatType& divide( float rhs );
    FloatType& divide( int rhs );
    FloatType& divide( double rhs );
    operator float() const {return *value;}

    private:
        float* value;
};

FloatType& FloatType::add( float rhs )
{    
    *value += rhs;
    return *this;
}

FloatType& FloatType::add( int rhs )
{    
    return add(static_cast<float>(rhs));
}

FloatType& FloatType::add( double rhs )
{    
    return add(static_cast<float>(rhs));
}

FloatType& FloatType::subtract( float rhs )
{
    *value -= rhs;
    return *this;    
}

FloatType& FloatType::subtract( int rhs )
{    
    return subtract(static_cast<float>(rhs));
}

FloatType& FloatType::subtract( double rhs )
{    
    return subtract(static_cast<float>(rhs));
}

FloatType& FloatType::multiply( float rhs )
{
    *value *= rhs;
    return *this;    
}

FloatType& FloatType::multiply( int rhs )
{    
    return multiply(static_cast<float>(rhs));
}

FloatType& FloatType::multiply( double rhs )
{    
    return multiply(static_cast<float>(rhs));
}

FloatType& FloatType::divide( float rhs )
{
    if (rhs == 0.0f) std::cout << "warning: floating point division by zero!" << std::endl;
    *value /= rhs;
    return *this;
}

FloatType& FloatType::divide( int rhs )
{
    return divide( static_cast<float>(rhs) );
}

FloatType& FloatType::divide( double rhs )
{
    return divide( static_cast<float>(rhs) );
}


struct DoubleType
{
    DoubleType( double d ): value( new double(d) ){}
    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& add( float rhs );        
    DoubleType& add( int rhs );

    DoubleType& subtract( double rhs );
    DoubleType& subtract( float rhs );
    DoubleType& subtract( int rhs );
 
    DoubleType& multiply( double rhs );
    DoubleType& multiply( float rhs );
    DoubleType& multiply( int rhs );


    DoubleType& divide( double rhs );
    DoubleType& divide( float rhs );
    DoubleType& divide( int rhs );

    operator double() const {return *value;}

    private:
        double* value;
};

DoubleType& DoubleType::add( double rhs )
{
    *value += rhs;
    return *this;    
}

DoubleType& DoubleType::add( float rhs )
{
    return add(static_cast<double>(rhs));
}

DoubleType& DoubleType::add( int rhs )
{
    return add(static_cast<double>(rhs));
}


DoubleType& DoubleType::subtract( double rhs )
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::subtract( float rhs )
{
    return subtract(static_cast<double>(rhs));
}

DoubleType& DoubleType::subtract( int rhs )
{
    return subtract(static_cast<double>(rhs));
}

DoubleType& DoubleType::multiply( double rhs )
{
    *value *= rhs;
    return *this;
}

DoubleType& DoubleType::multiply( float rhs )
{
    return multiply(static_cast<double>(rhs));
}

DoubleType& DoubleType::multiply( int rhs )
{
    return multiply(static_cast<double>(rhs));
}

DoubleType& DoubleType::divide( double rhs )
{
    if (rhs == 0.0) std::cout << "warning: floating point division by zero!" << std::endl;
    *value /= rhs;
    return *this;
}

DoubleType& DoubleType::divide( float rhs )
{
    return divide(static_cast<double>(rhs));
}

DoubleType& DoubleType::divide( int rhs )
{
    return divide(static_cast<double>(rhs));
}

struct IntType
{
    IntType (int i) : value ( new int(i) ){}
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& add( int rhs );
    IntType& add( float rhs );
    IntType& add( double rhs );

    IntType& subtract( int rhs );
    IntType& subtract( float rhs );
    IntType& subtract( double rhs );

    IntType& multiply( int rhs );
    IntType& multiply( float rhs );
    IntType& multiply( double rhs );

    IntType& divide( int rhs );
    IntType& divide( float rhs );
    IntType& divide( double rhs );

    operator int() const {return *value;}

    private:
        int* value;
};

IntType& IntType::add( int rhs )
{
    *value += rhs;
    return *this;
}

IntType& IntType::add( float rhs )
{
    return add(static_cast<int>(rhs));
}

IntType& IntType::add( double rhs )
{
    return add(static_cast<int>(rhs));
}

IntType& IntType::subtract( int rhs )
{
    *value -= rhs;
    return *this;
}

IntType& IntType::subtract( float rhs )
{
    return subtract(static_cast<int>(rhs));
}

IntType& IntType::subtract( double rhs )
{
    return subtract(static_cast<int>(rhs));
}


IntType& IntType::multiply( int rhs )
{
    *value *= rhs;
    return *this;
}

IntType& IntType::multiply( float rhs )
{
    return multiply(static_cast<int>(rhs));
}

IntType& IntType::multiply( double rhs )
{
    return multiply(static_cast<int>(rhs));
}


IntType& IntType::divide( int rhs )
{
    if (rhs == 0) 
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
    }
    else
    {
        *value /= rhs;
    }
    return *this;
}

IntType& IntType::divide( float rhs )
{
    return divide(static_cast<int>(rhs));
}

IntType& IntType::divide( double rhs )
{
    return divide(static_cast<int>(rhs));
}


void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 


    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ) << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ) << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(3) << std::endl << std::endl;
    std::cout << "Chain calculation = " << it.multiply(1000).divide(2).subtract(10).add(100) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f) << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << dt.multiply(it).divide(5.0f).add(ft) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0) << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0) << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0) << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();
    
    std::cout << "good to go!\n";

    return 0;
}

