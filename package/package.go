package centry

import (
	"github.com/jurgen-kluft/ccode/denv"
)

// GetPackage returns the package object of 'xentry'
func GetPackage() *denv.Package {

	// The main (xentry) package
	mainpkg := denv.NewPackage("centry")

	// 'xentry' library
	mainlib := denv.SetupDefaultCppLibProject("centry", "github.com\\jurgen-kluft\\centry")

	mainpkg.AddMainLib(mainlib)

	return mainpkg
}
