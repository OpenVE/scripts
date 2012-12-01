package main

import (
	"os"
	"strconv"
	"strings"
	"syscall"
	"time"
	"unsafe"
)

const (
	sleep  = time.Millisecond * 50
	bspace = " "
	bslash = "/"
	bstart = "["
	bfill  = "#"
	bempty = "-"
	bend   = "]"
	cr     = "\r"
	strto  = "to"
)

var cols int

func main() {
	var src, dst []string
	var to bool

	// Args a la carte
	for a := 1; a < len(os.Args); a++ {
		if os.Args[a] == strto {
			to = true
			continue
		}
		if !to {
			src = append(src, os.Args[a])
			continue
		}
		dst = append(dst, os.Args[a])
	}

	if !to {
		println("Usage:", os.Args[0], "source to destination")
		return
	}

	// Preparing the graphics
	ws, err := getWinsize()
	if err != nil {
		println(err)
		return
	}
	cols = int(ws.Col)

	lensrc := len(src)
	lendst := len(dst)
	var s, d int
	for s = 0; s < lensrc; s++ {
		for d = 0; d < lendst; d++ {
			Copy(src[s], dst[d])
		}
	}
}

func Copy(src, dst string) {

	// FileInfo
	stat_src, err := os.Stat(src)

	if err != nil {
		println(src, "does not exists")
		return
	}
	if stat_src.IsDir() {
		println(src, "is a directory")
		return
	}

	// FileInfo
	stat_dst, err := os.Stat(dst)

	if err == nil {
		if stat_dst.IsDir() {
			dst += stat_src.Name()
		}
	}

	// Preparing the files
	s, err := os.Open(src)
	if err != nil {
		println("Encountered problems with", src)
		return
	}
	d, err := os.Create(dst)
	if err != nil {
		println("Encountered problems with", dst)
		return
	}

	size := stat_src.Size()
	ssize := strconv.FormatInt(size, 10)
	prefix_size := len(src + bspace + strto + bspace + dst + bspace + ssize + bslash + ssize + bspace)
	bar_size := cols - (prefix_size + len(bstart+bend))
	bar_size64 := int64(bar_size)
	part := size / bar_size64
	diff := size - part*bar_size64

	// Looping buffers
	var prefix, bar string
	var read, wrote int
	var total int64
	prog := 0
	buffer := make([]byte, part)
	for total < size {
		if prog == bar_size {
			buffer = make([]byte, diff)
		}
		read, err = s.Read(buffer)
		if err != nil {
			println("Encountered problems with", src, "at", total/size)
			return
		}
		wrote, err = d.Write(buffer)
		if err != nil {
			println("Encountered problems with", dst, "at", total/size)
			return
		}
		if read < wrote {
			println("Encountered problems with", dst, "at", total/size)
			return
		}
		total += int64(wrote)
		prefix = src + bspace + strto + bspace + dst + bspace + strconv.FormatInt(total, 10) + bslash + strconv.FormatInt(size, 10)
		bar = prefix + bspace + bstart + strings.Repeat(bfill, prog) + strings.Repeat(bempty, bar_size-prog) + bend + cr
		os.Stdout.Write([]byte(bar))
		os.Stdout.Sync()
		if prog < bar_size {
			prog++
		}
	}

	prefix = src + bspace + strto + bspace + dst + bspace + strconv.FormatInt(total, 10) + bslash + strconv.FormatInt(size, 10)
	bar = prefix + " ok!"
	bar += strings.Repeat(bspace, bar_size)
	os.Stdout.Write([]byte(bar))
}

type winsize struct {
	Row    uint16
	Col    uint16
	Xpixel uint16
	Ypixel uint16
}

func getWinsize() (*winsize, error) {
	ws := new(winsize)

	r, _, err := syscall.Syscall(syscall.SYS_IOCTL, uintptr(syscall.Stdin), uintptr(syscall.TIOCGWINSZ), uintptr(unsafe.Pointer(ws)))

	if int(r) == -1 {
		return nil, os.NewSyscallError("getWisize", err)
	}
	return ws, nil
}
