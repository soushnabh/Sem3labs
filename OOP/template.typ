#import "@preview/codly:1.3.0": *

#let assignment(
  title: "",
  course: "",
  author: "",
  student_id: "",
  faculty: "Prof. [Faculty Name]",
  date: datetime.today().display("[month repr:long] [day], [year]"),
  body,
) = {
  // Document Metadata
  set document(author: author, title: title)

  // --------------------------------------------------------
  // Page setup: Hide header & footer on Page 1 (Cover page)
  // --------------------------------------------------------
  set page(
    paper: "a4",
    margin: (x: 1.25in, y: 1.25in),
    header: context {
      // Only show running header on page 2 onwards
      if counter(page).get().first() > 1 [
        #align(right)[
          #text(9pt, fill: luma(130))[
            #course | #title | #author
          ]
        ]
      ]
    },
    footer: context {
      // Only show page numbers on page 2 onwards
      if counter(page).get().first() > 1 [
        #align(center)[
          #text(9pt, fill: luma(130))[
            Page #counter(page).display("1 of 1", both: true)
          ]
        ]
      ]
    }
  )

  // Typography configuration
  set text(font: "Libertinus Serif", size: 11pt)
  set par(justify: true, leading: 0.7em)

  // Headings
  show heading: set text(font: ("DejaVu Sans", "Liberation Sans", "sans-serif"))
  show heading.where(level: 1): it => box(
    margin: (bottom: 0.5em, top: 1.2em),
    text(weight: "bold", size: 14pt, fill: rgb("#111827"), it)
  )
  show heading.where(level: 2): it => box(
    text(weight: "bold", size: 12pt, fill: rgb("#374151"), it)
  )

  // --------------------------------------------------------
  // Code Styling with Codly
  // --------------------------------------------------------
  show raw: set text(
    font: ("JetBrainsMono Nerd Font", "Fira Code", "DejaVu Sans Mono"),
    size: 9pt
  )

  // Inline snippet highlight (`code`)
  show raw.where(block: false): box.with(
    fill: rgb("#f1f5f9"),
    inset: (x: 4pt, y: 1pt),
    outset: (y: 2pt),
    radius: 3pt,
    stroke: 0.5pt + rgb("#cbd5e1"),
  )

  // Multi-line code blocks
  show: codly-init.with()
  codly(
    languages: (
      cpp: (name: "C++", color: rgb("#00599C")),
      py: (name: "Python", color: rgb("#3572A5")),
    ),
    zebra-fill: none,
    stroke: 0.5pt + rgb("#e2e8f0"),
    fill: rgb("#f8fafc"),
    radius: 5pt,
  )

  // --------------------------------------------------------
  // Formal Academic Cover Page (Page 1)
  // --------------------------------------------------------
  align(center)[
    #v(0.5cm)
    #text(16pt, weight: "bold")[NAGALAND UNIVERSITY] \
    #v(0.2em)
    #text(9pt, fill: rgb("#64748b"))[(A Central University Established by an Act of Parliament 1989)] \
    #v(0.4em)
    #text(12pt, weight: "bold", fill: rgb("#334155"))[SCHOOL OF ENGINEERING AND TECHNOLOGY] \
    #v(0.2em)
    #text(11pt, weight: "bold")[DEPARTMENT OF INFORMATION TECHNOLOGY] \
    #v(0.1em)
    #text(9.5pt, fill: rgb("#64748b"))[Kohima Campus, Nagaland – 797004]

    // University Logo
    #image("nu logo.png", width: 6cm)

    #line(length: 60%, stroke: 1.2pt + rgb("#1e293b"))
    #v(0.4em)
    #text(22pt, weight: "bold", font: ("DejaVu Sans", "sans-serif"))[#title]
    #v(0.4em)
    #text(13pt, fill: rgb("#475569"))[#course]
    #v(0.4em)
    #line(length: 60%, stroke: 1.2pt + rgb("#1e293b"))

    #v(2.2cm)

    // Side-by-side Submitted By & Submitted To
    #grid(
      columns: (1fr, 1fr),
      align: (left, right),
      [
        *Submitted By:* \
        #author \
        Roll / ID: #student_id \
        Semester: 3rd Sem \
      ],
      [
        *Submitted To:* \
        #faculty \
        Assistant Professor \
        Dept. of IT \
      ]
    )

    #v(1.5cm)
    #text(10pt, fill: luma(110))[Date: #date]
  ]

  // Clean break to send Question 1 to Page 2
  pagebreak()

  // Render document body
  body
}
