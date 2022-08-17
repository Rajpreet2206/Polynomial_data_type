#include<iostream>
using namespace std;

				
				template<typename T =int>//The value T specifies the types of coefficients and variables
				class Pol{
					public:
					Pol(vector<T>& c = vector<T>(1)):coef_(c), deg_(c.size()-1){}
					Pol(size_t n): coef_(vector<T>(n+1)), deg_(n){}
					Pol(const Pol& p): coef_(p.coef_), deg_(p.deg_){}
					~Pol(){}
					Pol& operator=(const Pol& p){deg_ = p.deg_; coef_ = p.coef_ ; return *this;}
															
					Pol operator+() const{return *this;}
					Pol operator-() const{Pol r(deg_);
						for(unsigned int i = 0; i<= deg_; i++){
							r.coef_[i] = -coef_[i];
						}
					return r;
					}
																																				
					Pol operator+(const Pol& p) const{Pol r(max(p.deg_, deg_));
						vector<T> v;
						if(deg_ > p.deg_){v = p.coef_; r.coef_ = coef_;}
						else { v = coef_; r.coef_ = p.coef_ ;}
						for(unsigned int i=0; i<= min(p.deg_, deg_); i++){
							r.coef_[i] = t.coef_[i]+v[i]; 
						}
						return r;
					}
		
					Pol operator-(const Pol& p) const {return *this + (-p);}
																																						
					friend ostream& operator<<(ostream& os, const Pol& p){ 
						int j;
						for(j=p.deg_; j>=0; --j){
							if(static_cast<T>(0) != p.coef_[j]) break;
							}
						if(j < 0) os << 0;
						else
						if(0 == j ) os << p.coef_[j];
						else os << p.coef_[j] << "X^"<< j;
						for(int i= j-1; i>=0; --i){
							if(static_cast<T>(0) != p.coef_[i]{
								if(0 != i)
									if(static_cast<T>(1) != p.coef_[i])
										os << " + " << p.coef_[i] << "X^"<<i;
									else 
										os <<" + " <<"X^"<<i;
								else 
									os << " + "<< p.coef_[i];
								}
							}	
						os << ".";
						return os;
						}
																																																																																																																																	
					friend istream& operator>>(istream& is, Pol& p){
						cout<<"Enter the degree of Polynomial ";
						is >> p.deg_;
						p.coef_.resize(p.deg_ + 1);
						cout<<"Enter all the Coefficients like a0 + a1*x + a2*x^2 + ..... + an*x^n" << endl;
						for(unsigned int i=0; i<= p.deg_; i++){
							is >> p.coef_[i];
						}
					return is;
					}
																																																																																																																																			
//Evaluation of the polynomial 
					T operator()(const T& x){
					T value =0;
					for(int i = deg_; i >= 0; i--){
						value = value* x + coef_[i];
					}
					return value;
					}

			private:
				vector<T> coef_;
				size_t deg_;
				template<typename T> inline static max(T a, T b) { return a > b ? a : b}
				template<typename T> inline static min(T a, T b) { return a < b ? a : b}	
																																																																																																																																					//																											        			
						
};


int main(int argc, char* argv[]){
	vector<int> v = {1,2,1};
	Pol<int> p(v); 
	cout<<"P(X): "<< p << endl;
        cout<<"P(2) = " <<p(2) << endl;
	return 0;
}
