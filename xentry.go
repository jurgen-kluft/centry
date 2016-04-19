package main

import (
	"github.com/jurgen-kluft/xcode"
	"github.com/jurgen-kluft/xentry/package"
)

func main() {
	xcode.Generate(xentry.GetPackage())
}
