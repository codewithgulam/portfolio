const b2t = ScrollReveal({
    origin: 'bottom',
    distance: '80px',
    duration: 2000,
    reset: true
})

b2t.reveal('.container-python')
b2t.reveal('.container-java',{delay:100})
b2t.reveal('.container-cpp',{delay:300})
b2t.reveal('.container-js',{delay:500})
b2t.reveal('.grid-item',{delay:250})
