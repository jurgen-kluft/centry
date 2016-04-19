package xentry

import (
	"github.com/jurgen-kluft/xcode/denv"
)

// GetPackage returns the package object of 'xentry'
func GetPackage() *denv.Package {

	// The main (xentry) package
	mainpkg := denv.NewPackage("xentry")

	// 'xentry' library
	mainlib := denv.SetupDefaultCppLibProject("xentry", "github.com\\jurgen-kluft\\xentry")
	mainpkg.AddMainLib(mainlib)

	return mainpkg
}
