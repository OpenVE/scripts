package main

import (
	"github.com/russross/blackfriday"
	"html/template"
	"io/ioutil"
	"net/http"
)

type Page struct {
	Title string
	Body  template.HTML
}

func loadPage(title string) (*Page, error) {
	filename := "markdown_" + title + ".md"
	body, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	body = blackfriday.MarkdownCommon(body)
	html := template.HTML(body)
	return &Page{Title: title, Body: html}, nil
}

func handler(w http.ResponseWriter, r *http.Request) {
	title := r.URL.Path[1:]
	page, _ := loadPage(title)
	view, _ := template.ParseFiles("view.html")
	view.Execute(w, page)
}

func main() {
	http.HandleFunc("/", handler)
	http.ListenAndServe(":8080", nil)
}
