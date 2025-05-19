package centry

import (
	"github.com/jurgen-kluft/ccode/denv"
)

// GetPackage returns the package object of 'centry'
func GetPackage() *denv.Package {

	// The main (centry) package
	mainpkg := denv.NewPackage("centry")

	// 'centry' library
	mainlib := denv.SetupCppLibProject("centry", "github.com\\jurgen-kluft\\centry")

	mainpkg.AddMainLib(mainlib)

	return mainpkg
}
