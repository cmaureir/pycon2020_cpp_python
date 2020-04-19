// 3. On Reveal.js ready event, copy header/footer <div> into each `.slide-background` <div>
var header = $('#header').html();
if ( window.location.search.match( /print-pdf/gi ) ) {
  Reveal.addEventListener( 'ready', function( event ) {
    $('.slide-background').append(header);
  });
}
else {
  $('div.reveal').append(header);
 }
