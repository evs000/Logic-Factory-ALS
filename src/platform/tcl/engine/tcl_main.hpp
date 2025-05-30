#pragma once

#include "tcl_script.hpp"
#include "tcl_cmd.hpp"
#include "tcl_option.hpp"
#include "tcl_encode.hpp"

#include <iostream>
#include <sstream>

namespace lf
{
namespace tcl
{

static int defaultInit();

class TclMain
{
public:
  static TclMain* getInstance()
  {
    static TclMain* instance = new TclMain();
    return instance;
  }

  // run with tcl script file
  static int tcl_main( const char* file_path )
  {
    int argc = 1;
    char** argv = new char*[2];
    argv[0] = const_cast<char*>( "TclMain\n" );

    if ( file_path )
    {
      argc = 2;
      if ( argv == nullptr )
      {
        std::cerr << "fail to malloc memery\n";
        return EXIT_FAILURE;
      }
      argv[1] = const_cast<char*>( file_path );
    }

    auto* script_engine = TclScript::getOrCreateInstance();

    Tcl_MainEx( argc, argv, initSetting, script_engine->get_interp() );

    delete[] argv;
    return EXIT_SUCCESS;
  }

  // run with commands
  static int tcl_main( int argc, char** argv )
  {
    auto* script_engine = TclScript::getOrCreateInstance();

    if ( argc == 1 )
    {
      Tcl_MainEx( argc, argv, initSetting, script_engine->get_interp() );
      return EXIT_SUCCESS;
    }
    else
    {
      // register the commands
      initSetting( script_engine->get_interp() );

      // run the commands
      for ( int i = 1; i < argc; ++i )
      {
        if ( Tcl_Eval( script_engine->get_interp(), argv[i] ) == TCL_ERROR )
        {
          std::cerr << "Error running Tcl command: " << Tcl_GetStringResult( script_engine->get_interp() ) << std::endl;
          return EXIT_FAILURE;
        }
      }
      return EXIT_SUCCESS;
    }
  }

  static void displayHelp()
  {
    std::cerr << "\033[49;32m"
                 "Enter \033[1mexit\033[0m\033[49;32m to quit."
                 "\033[0m\n";
  }

  static void set_init_func( int ( *initFunction )() )
  {
    _user_init = initFunction;
  }

private:
  TclMain() = default;

  ~TclMain() = default;

  static int initSetting( Tcl_Interp* interp ) { return _user_init(); }

  static int ( *_user_init )();

}; // class TclMain

int ( *TclMain::_user_init )() = defaultInit;

static int defaultInit()
{
  std::cerr << "notice: no user defined initialized function\n";
  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf