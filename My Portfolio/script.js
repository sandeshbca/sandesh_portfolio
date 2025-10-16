    // small utilities
    document.getElementById('year').textContent = new Date().getFullYear();

    // typing animation for role
    (function(){
      const el = document.getElementById('role');
      const words = ['BCA Student','Python Developer','Frontend Enthusiast','Creative Coder'];
      let w=0, i=0, forward=true;
      function tick(){
        const word = words[w];
        el.textContent = word.slice(0,i);
        if(forward){
          if(i<word.length) i++;
          else { forward=false; setTimeout(tick,900); return }
        } else {
          if(i>0) i--;
          else { forward=true; w=(w+1)%words.length }
        }
        setTimeout(tick, forward?90:45);
      }
      tick();
    })();

    // canvas particle background
    (function(){
      const canvas = document.getElementById('bgcanvas');
      const ctx = canvas.getContext('2d');
      let W, H, particles=[];
      function resize(){ W=canvas.width = innerWidth; H=canvas.height=innerHeight }
      addEventListener('resize', resize);
      resize();

      function rand(min,max){return Math.random()*(max-min)+min}
      class P{constructor(){this.reset()} reset(){this.x=rand(0,W);this.y=rand(0,H);this.vx=rand(-0.3,0.3);this.vy=rand(-0.6,0.6);this.r=rand(0.6,2.6);this.alpha=rand(0.06,0.35)}}
      for(let i=0;i<120;i++) particles.push(new P());

      function draw(){
        ctx.clearRect(0,0,W,H);
        // soft gradient overlay
        const g = ctx.createLinearGradient(0,0,W,H);
        g.addColorStop(0, 'rgba(12,18,34,0.12)');
        g.addColorStop(1, 'rgba(4,6,12,0.18)');
        ctx.fillStyle = g; ctx.fillRect(0,0,W,H);

        for(let p of particles){
          p.x += p.vx; p.y += p.vy;
          if(p.x< -50) p.x = W+50; if(p.x>W+50) p.x=-50; if(p.y>H+50) p.y=-50; if(p.y<-50) p.y=H+50;
          ctx.beginPath();
          ctx.fillStyle = `rgba(124,92,255,${p.alpha})`;
          ctx.arc(p.x,p.y,p.r,0,Math.PI*2);
          ctx.fill();
        }

        // draw subtle connections
        for(let i=0;i<particles.length;i++){
          for(let j=i+1;j<particles.length;j++){
            const a=particles[i], b=particles[j];
            const dx=a.x-b.x, dy=a.y-b.y; const d = dx*dx+dy*dy;
            if(d<9000){
              const alpha = 0.018*(1 - d/9000);
              ctx.strokeStyle = `rgba(50,223,255,${alpha})`;
              ctx.lineWidth = 0.6; ctx.beginPath(); ctx.moveTo(a.x,a.y); ctx.lineTo(b.x,b.y); ctx.stroke();
            }
          }
        }

        requestAnimationFrame(draw);
      }
      draw();

      // subtle mouse repel
      let mx=-9999,my=-9999; addEventListener('mousemove', (e)=>{mx=e.clientX;my=e.clientY});
      setInterval(()=>{
        for(let p of particles){
          const dx = p.x - mx, dy = p.y - my; const d2 = dx*dx+dy*dy;
          if(d2<90000){ p.vx += dx*0.000008; p.vy += dy*0.000012 }
        }
      },40)
    })();

    // accessibility: focus outlines for keyboard users
    document.body.addEventListener('keydown', function(e){ if(e.key==='Tab'){ document.documentElement.style.scrollBehavior='smooth' } });

    // small progressive enhancement: reveal project data (demo)
    document.querySelectorAll('.proj').forEach((p,idx)=>{ p.style.opacity=0; p.style.transform='translateY(8px)'; setTimeout(()=>{ p.style.transition='all .6s cubic-bezier(.2,.9,.2,1)'; p.style.opacity=1; p.style.transform='translateY(0)'; }, 220*idx) })