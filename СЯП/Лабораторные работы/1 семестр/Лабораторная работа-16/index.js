let main = document.getElementById("link-main");
  main.addEventListener("click", function() {
    window.location.href = "index.html";
  });
  main.addEventListener("mouseover", function() {
    main.style.backgroundColor = "darkgray";
  });
  main.addEventListener("mouseout", function() {
    main.style.backgroundColor = "";
  });

  let obz = document.getElementById("link-obz");
  obz.addEventListener("click", function() {
    window.location.href = "second.html";
  });
  obz.addEventListener("mouseover", function() {
    obz.style.backgroundColor = "darkgray";
  });
  obz.addEventListener("mouseout", function() {
    obz.style.backgroundColor = "";
  });


  let contact = document.getElementById("link-contact");
  contact.addEventListener("click", function() {
    window.location.href = "contact.html";
  });
  contact.addEventListener("mouseover", function() {
    contact.style.backgroundColor = "darkgray";
  });
  contact.addEventListener("mouseout", function() {
    contact.style.backgroundColor = "";
  });

