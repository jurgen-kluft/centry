package centry

import (
	"github.com/jurgen-kluft/ccode/denv"
)

const (
	repo_path = "github.com\\jurgen-kluft"
	repo_name = "centry"
)

// GetPackage returns the package object of 'centry'
func GetPackage() *denv.Package {
	name := repo_name

	// main package
	mainpkg := denv.NewPackage(repo_path, repo_name)

	// main library
	mainlib := denv.SetupCppLibProject(mainpkg, name)

	mainpkg.AddMainLib(mainlib)
	return mainpkg
}
