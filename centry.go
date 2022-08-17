package main

import (
	"github.com/jurgen-kluft/ccode"
	centry "github.com/jurgen-kluft/centry/package"
)

func main() {
	ccode.Generate(centry.GetPackage())
}
