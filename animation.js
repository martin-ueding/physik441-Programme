// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

var l = 100;

var start = function(filename) {
	paper = Raphael("holder", 4*l, 4*l+10);
	midpoint = paper.circle(2*l, 2*l, 5);
	s1 = paper.circle(2*l, 3*l, 10);
	s2 = paper.circle(2*l, 4*l, 10);
	midpoint.attr("fill", "#000");
	midpoint.attr("stroke", "#000");
	s1.attr("fill", "#0A0");
	s1.attr("stroke", "#000");
	s2.attr("fill", "#00A");
	s2.attr("stroke", "#00");

	$("#data").load(filename, 0, function(response, status, xml) {
		data = response;
		start_animation();
	});
};

var start_animation = function() {
	lines = data.split("\n");
	i = 0;
	oldtime = -.1;
	animation_step();
}

var animation_step = function() {
	if (i >= lines.length)
		return;
		line = lines[i];
		var words = line.trim().split(/\s+/);

		var t = words[0];
		var phi1 = words[1];
		var phi2 = words[2];

		if (phi1 == undefined)
			return;

		var x1 = l* Math.cos(phi1 - Math.PI/2) + 2*l;
		var y1 = l* Math.sin(phi1 - Math.PI/2) + 2*l;
		var x2 = x1 + l* Math.cos(phi2 - Math.PI/2);
		var y2 = y1 + l* Math.sin(phi2 - Math.PI/2);


		y1 = 4*l - y1;
		y2 = 4*l - y2;

		//console.debug([t, phi1, phi2]);
		//console.debug([x1, y1, x2, y2]);

		var a1 = Raphael.animation({"cx": x1, "cy": y1}, (t-oldtime)*1000, "linear", animation_step);
		var a2 = Raphael.animation({"cx": x2, "cy": y2}, (t-oldtime)*1000, "linear");

		s1.animate(a1);
		s2.animate(a2);

		oldtime = t;

		i += 30;
}

start("out/3-rk.txt");
