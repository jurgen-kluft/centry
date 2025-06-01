package centry

import (
	"github.com/jurgen-kluft/ccode/denv"
)

// GetPackage returns the package object of 'centry'
func GetPackage() *denv.Package {

	// The main (centry) package
	mainpkg := denv.NewPackage("github.com\\jurgen-kluft", "centry")

	// 'centry' library
	mainlib := denv.SetupCppLibProject(mainpkg, "centry")

	mainpkg.AddMainLib(mainlib)

	return mainpkg
}
