(define page
  '((h2 "news")

    (news
     (@ (date "17 July 2007")
        (title "guile-cairo 1.3.93 available"))
     (code "guile-cairo") " 1.3.93 has been released, featuring " (rlink "docs/" "documentation") ".")

    (news
     (@ (date "12 June 2007")
        (title "guile-cairo 1.3.92 available"))
     (code "guile-cairo") " 1.3.92 has been released, featuring input from and output to Scheme ports.")

    (news
     (@ (date "8 June 2007")
        (title "guile-cairo 1.3.91 available"))
     (code "guile-cairo") " 1.3.91 has been released, featuring Cairo 1.2 support.")

    (news
     (@ (date "18 May 2007")
        (title "initial release"))
     (code "guile-cairo") " 1.3.90 released.")

    ))


(load "../template.scm")

(define (news tag args . body)
  `(div (h4 ,@(assq-ref (cdr args) 'date) ": "
            ,@(assq-ref (cdr args) 'title))
        (p ,@body)))

(define (make-index)
  (output-html page "guile-cairo: news" "news" "../"
               #:transform-rules `((news . ,news))))
