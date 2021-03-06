/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:
     std::vector <Monomio> vector;
   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio
    inline Polinomio()
    {
      this->vector.clear();
      Monomio m;
      this->vector.push_back(m);
      #ifndef NDEBUG
        assert( this->esNulo() == true );
      #endif
    }

    inline Polinomio(const Polinomio &p)
    {
      this->vector = p.vector;
      #ifndef NDEBUG
        for(int i = 0; i < this->getNumeroMonomios(); i++)
        {
          assert( (this->vector[i] == p.vector[i]) );
        }
      #endif
    }

  //! \name Observadores: funciones de consulta de la clase Polinomio
    inline bool esNulo() const
    {
      if( (this->getNumeroMonomios() == 1) && (this->vector[0] == 0.0))
      {
          return true;
      }
      return false;
    }

    inline int getGrado() const
    {
      return this->vector.front().getGrado(); //devuelve el grado del primer elemento que deberia ser el de mayor grado cuando esté ordenado
    }

    inline int getNumeroMonomios() const
    {
      return this->vector.size();
    }

    inline bool existeMonomio(int n) const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if(this->vector[i].getGrado() == n)
        {
          return true;
        }
      }
      return false;
    }

    inline Monomio & getMonomio(int n)
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      ed::Monomio *m = new ed::Monomio();

      for(int i = 0; i < this->getNumeroMonomios(); i++)
      {
        if(this->vector[i].getGrado() == n)
        {
          *m = this->vector[i];
        }
      }
      return *m;
    }

    //Funcion que obtiene el monomio en cuestion pasada una posicion del polinomio concreta
    inline Monomio obtieneMonomio(int n) const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      return this->vector[n];
    }

    //funcion extra: comprueba si un polinomio está ordenado
    inline bool isOrdered() const
    {
      #ifndef NDEBUG
        assert( this->esNulo() == false );
      #endif

      for( int i = 0; i < this->getNumeroMonomios()-1; i++)
      {
        if( this->vector[i].getGrado() <= this->vector[i+1].getGrado() )
        {
          return false;
        }
      }
      return true;
    }


  inline void addMonomio(Monomio const &m)
  {
    this->vector.push_back(m);
    #ifndef NDEBUG
      assert( this->vector.back() == m );
    #endif
  }

  inline void remove(int n)
  {
    #ifndef NDEBUG
      assert( this->getNumeroMonomios() >= n );
    #endif
    int old = this->getNumeroMonomios();
    this->vector.erase(this->vector.begin()+n);
    #ifndef NDEBUG
      assert( this->getNumeroMonomios() == (old-1) );
    #endif
  }

	//! \name Funciones de modificación de la clase Polinomio
  //funcion extra: ordena un polinomio desordenado y agrupa aquellos monomios con mismo grado
  void ordenaPolinomio();
	// COMPLETAR

 	////////////////////////////////////////////////////////////////

  //! \name Operadores de la clase Polinomio
	Polinomio & operator=(Polinomio const &p);
	Polinomio & operator=(Monomio const &m);
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación
	Polinomio & operator+=(Polinomio const &p);
  Polinomio & operator+=(Monomio const &m);
  Polinomio & operator+=(double const &x);

  Polinomio & operator-=(Polinomio const &p);
  Polinomio & operator-=(Monomio const &m);
  Polinomio & operator-=(double const &x);

  Polinomio & operator*=(Polinomio const &p);
  Polinomio & operator*=(Monomio const &m);
  Polinomio & operator*=(double const &x);

  Polinomio & operator/=(Polinomio const &p);
  Polinomio & operator/=(Monomio const &m);
  Polinomio & operator/=(double const &x);


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio
  void leerPolinomio();
  void escribirPolinomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

  double calcularValor(double const &x);

}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
