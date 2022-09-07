package main

import (
	"github.com/jurgen-kluft/ccode"
	centry "github.com/jurgen-kluft/centry/package"
)

func main() {
	ccode.Init()
	ccode.Generate(centry.GetPackage())
}
